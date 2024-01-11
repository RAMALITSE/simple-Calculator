#pragma once
#include <map>
#include <string>

class Parcer
{
private:
    virtual bool isOperators(char c) {
        return false; 
    }public:
    virtual double evaluateExpression(const std::string& expression, std::map<std::string, double>& variables) {
        return 0.0; 
    }
};