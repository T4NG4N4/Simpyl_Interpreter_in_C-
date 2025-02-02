#ifndef SIMPYLINTERPRETER_H
#define SIMPYLINTERPRETER_H

#include "MemoryManager.h"
#include "Debugger.h"
#include "FunctionManager.h"
#include "ModuleManager.h"
#include <unordered_map>
#include <string>

class SimpylInterpreter {
public:
    SimpylInterpreter();
    void execute_command(const std::string& command);
    void run();
    void call_python_function(const std::string& module_name, const std::string& function_name, const std::vector<std::string>& args);

private:
    void handle_variable_assignment(const std::string& command);
    void handle_print(const std::string& command);
    std::string evaluate_expression(const std::string& expression);
    void handle_function_call(const std::string& command);

    std::unordered_map<std::string, std::string> variables;
    MemoryManager memory_manager;
    Debugger debugger;
    FunctionManager function_manager;
    ModuleManager module_manager;
    int command_count;
};

#endif // SIMPYLINTERPRETER_H