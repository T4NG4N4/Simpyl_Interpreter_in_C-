#include "FunctionManager.h"
#include <iostream>
#include <regex>

void FunctionManager::handle_function_definition(const std::string& command) {
    std::regex re(R"(\(define\s+\((\w+)\s*(.*?)\)\s*\((.*?)\)\))");
    std::smatch match;
    if (std::regex_match(command, match, re)) {
        std::string func_name = match[1];
        std::string params = match[2];
        std::string body = match[3];

        std::vector<std::string> param_list;
        if (!params.empty()) {
            std::regex param_re(R"(\s+)");
            std::sregex_token_iterator iter(params.begin(), params.end(), param_re, -1);
            std::sregex_token_iterator end;
            for (; iter != end; ++iter) {
                param_list.push_back(*iter);
            }
        }

        functions[func_name] = {param_list, body};
        std::cout << "Función '" << func_name << "' definida con parámetros ";
        for (const auto& param : param_list) {
            std::cout << param << " ";
        }
        std::cout << "." << std::endl;
    } else {
        throw std::runtime_error("Error de sintaxis en la definición de la función.");
    }
}

void FunctionManager::handle_lambda_definition(const std::string& command) {
    std::regex re(R"(\(lambda\s+\((.*?)\)\s*\((.*?)\)\))");
    std::smatch match;
    if (std::regex_match(command, match, re)) {
        std::string params = match[1];
        std::string body = match[2];
        // Lógica para almacenar y manejar la función lambda
    } else {
        throw std::runtime_error("Error de sintaxis en la definición de la función lambda.");
    }
}