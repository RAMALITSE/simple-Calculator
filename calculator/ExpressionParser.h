#pragma once
#include "Parcer.h"


class ExpressionParser : public Parcer {
private:
    std::map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
    };

public:
    bool isOperators(char c) override;

    double evaluateExpression(const std::string& expression, std::map<std::string, double>& variables) override;
   
};
