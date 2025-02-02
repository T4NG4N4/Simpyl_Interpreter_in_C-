#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <string>
#include <unordered_map>

class ModuleManager {
public:
    void load_module(const std::string& module_name);

private:
    std::unordered_map<std::string, void*> loaded_modules;
};

#endif // MODULEMANAGER_H