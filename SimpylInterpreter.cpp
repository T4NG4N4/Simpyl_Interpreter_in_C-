#include "SimpylInterpreter.h"
#include <Python.h>
#include <iostream>
#include <regex>

SimpylInterpreter::SimpylInterpreter()
    : memory_manager(100, 10), command_count(0) {}

void SimpylInterpreter::execute_command(const std::string& command) {
    try {
        if (command.find("(import") == 0) {
            std::string module_name = command.substr(8, command.size() - 9);
            module_manager.load_module(module_name);
        } else if (std::regex_match(command, std::regex(R"(\(define )"))) {
            function_manager.handle_function_definition(command);
        } else if (std::regex_match(command, std::regex(R"(\(\w+ = )"))) {
            handle_variable_assignment(command);
        } else if (command.find("(print") == 0) {
            handle_print(command);
        } else if (std::regex_match(command, std::regex(R"(\(\w+\s)"))) {
            handle_function_call(command);
        } else {
            std::cout << "Comando no reconocido. Asegúrate de que la sintaxis sea correcta." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error al ejecutar el comando: " << e.what() << std::endl;
    }
}

void SimpylInterpreter::run() {
    std::cout << "Bienvenido a Simpyl. Escriba 'exit' para salir." << std::endl;
    while (true) {
        try {
            std::cout << "Simpyl> ";
            std::string command;
            std::getline(std::cin, command);
            if (command == "exit") {
                std::cout << "Saliendo de Simpyl..." << std::endl;
                break;
            }
            execute_command(command);
            command_count++;
            memory_manager.monitor_memory(command_count);
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << ". Verifica la sintaxis o el comando." << std::endl;
        }
    }
}

void SimpylInterpreter::handle_variable_assignment(const std::string& command) {
    std::regex re(R"(\((\w+) = (.*?)\))");
    std::smatch match;
    if (std::regex_match(command, match, re)) {
        std::string var_name = match[1];
        std::string expression = match[2];

        std::string value = evaluate_expression(expression);
        variables[var_name] = value;
        std::cout << var_name << " asignado con valor " << value << std::endl;
    } else {
        throw std::runtime_error("Error al asignar variable.");
    }
}

void SimpylInterpreter::handle_print(const std::string& command) {
    std::string expression = command.substr(7, command.size() - 8);
    std::string value = evaluate_expression(expression);
    std::cout << value << std::endl;
}

std::string SimpylInterpreter::evaluate_expression(const std::string& expression) {
    // Implementar la lógica para evaluar la expresión de manera segura.
    return expression; // Placeholder
}

void SimpylInterpreter::handle_function_call(const std::string& command) {
    std::regex re(R"(\((\w+)\s*(.*?)\))");
    std::smatch match;
    if (std::regex_match(command, match, re)) {
        std::string func_name = match[1];
        std::string params = match[2];

        std::vector<std::string> param_values;
        if (!params.empty()) {
            std::regex param_re(R"(\s+)");
            std::sregex_token_iterator iter(params.begin(), params.end(), param_re, -1);
            std::sregex_token_iterator end;
            for (; iter != end; ++iter) {
                param_values.push_back(evaluate_expression(*iter));
            }
        }

        const auto& func = function_manager.functions.at(func_name);
        std::unordered_map<std::string, std::string> local_vars;
        for (size_t i = 0; i < func.params.size(); ++i) {
            local_vars[func.params[i]] = param_values[i];
        }
        // Aquí deberías implementar la lógica para ejecutar el cuerpo de la función.
    } else {
        throw std::runtime_error("Error en la llamada a la función.");
    }
}

void SimpylInterpreter::call_python_function(const std::string& module_name, const std::string& function_name, const std::vector<std::string>& args) {
    Py_Initialize();
    PyObject* pName = PyUnicode_DecodeFSDefault(module_name.c_str());
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, function_name.c_str());
        if (PyCallable_Check(pFunc)) {
            PyObject* pArgs = PyTuple_New(args.size());
            for (size_t i = 0; i < args.size(); ++i) {
                PyObject* pValue = PyUnicode_DecodeFSDefault(args[i].c_str());
                PyTuple_SetItem(pArgs, i, pValue);
            }
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != nullptr) {
                std::cout << "Resultado de la llamada a Python: " << PyUnicode_AsUTF8(pValue) << std::endl;
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }
    Py_Finalize();
}