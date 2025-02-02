#include "MemoryManager.h"
#include <iostream>

MemoryManager::MemoryManager(int threshold, int check_interval)
    : memory_threshold(threshold), check_interval(check_interval) {}

void MemoryManager::monitor_memory(int command_count) {
    if (command_count % check_interval == 0) {
        int memory_usage = get_memory_usage();
        if (memory_usage > memory_threshold) {
            std::cout << "Uso de memoria alto: " << memory_usage << " MB. Ejecutando recolección de basura." << std::endl;
        }
    }
}

int MemoryManager::get_memory_usage() {
    // Implementar la lógica para obtener el uso de memoria en MB.
    return 0; // Placeholder
}