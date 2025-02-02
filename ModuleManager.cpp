#include "ModuleManager.h"
#include <iostream>

void ModuleManager::load_module(const std::string& module_name) {
    // Aquí deberías implementar la lógica para cargar el módulo.
    // En este ejemplo, solo imprimimos un mensaje.
    std::cout << "Módulo '" << module_name << "' cargado con éxito." << std::endl;
}