#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <unordered_map>
#include <string>

class Debugger {
public:
    Debugger();
    void enable_debug();
    void disable_debug();
    void add_breakpoint(int line, const std::string& condition = "");
    void remove_breakpoint(int line);
    void inspect_variable(const std::unordered_map<std::string, std::string>& variables, const std::string& var_name);
    void show_call_stack();

private:
    bool debug_mode;
    std::unordered_map<int, std::string> breakpoints;
};

#endif // DEBUGGER_H