#include "Debugger.h"
#include <iostream>

Debugger::Debugger() : debug_mode(false) {}

void Debugger::enable_debug() {
    debug_mode = true;
    std::cout << "Modo de depuración habilitado. Usa '(inspect <variable>)' para ver el valor de las variables." << std::endl;
}

void Debugger::disable_debug() {
    debug_mode = false;
    std::cout << "Modo de depuración deshabilitado." << std::endl;
}

void Debugger::add_breakpoint(int line, const std::string& condition) {
    breakpoints[line] = condition;
    std::cout << "Punto de interrupción añadido en la línea " << line << ". Condición: " << (condition.empty() ? "Ninguna" : condition) << "." << std::endl;
}

void Debugger::remove_breakpoint(int line) {
    if (breakpoints.find(line) != breakpoints.end()) {
        breakpoints.erase(line);
        std::cout << "Punto de interrupción eliminado de la línea " << line << "." << std::endl;
    } else {
        std::cout << "No hay punto de interrupción en la línea " << line << "." << std::endl;
    }
}

void Debugger::inspect_variable(const std::unordered_map<std::string, std::string>& variables, const std::string& var_name) {
    auto it = variables.find(var_name);
    if (it != variables.end()) {
        std::cout << var_name << " = " << it->second << std::endl;
    } else {
        std::cout << "Variable '" << var_name << "' no encontrada." << std::endl;
    }
}

void Debugger::show_call_stack() {
    std::cout << "Pila de llamadas:" << std::endl;
    // Aquí deberías implementar la lógica para mostrar la pila de llamadas.
}