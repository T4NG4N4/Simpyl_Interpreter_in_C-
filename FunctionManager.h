#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

class FunctionManager {
public:
    void handle_function_definition(const std::string& command);
    void handle_lambda_definition(const std::string& command);

private:
    struct Function {
        std::vector<std::string> params;
        std::string body;
    };

    std::unordered_map<std::string, Function> functions;
};

#endif // FUNCTIONMANAGER_H