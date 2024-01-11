#include <map>
#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>
#include "ExpressionParser.h"
#include "simpleCalculations.h"

bool ExpressionParser::isOperators(char c) {
    return precedence.find(c) != precedence.end();
}

double ExpressionParser::evaluateExpression(const std::string& expression, std::map<std::string, double>& variables) {

    try
    {
        std::stack<char> operators;
        std::stack<double> operands;

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == ' ') {
                continue; // Skip whitespace
            }
            else if (isdigit(expression[i])) {
                std::string operand;
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                    operand += expression[i++];
                }
                i--;
                operands.push(stod(operand));
            }
            else if (isalpha(expression[i])) {
                std::string variable;
                while (i < expression.length() && isalpha(expression[i])) {
                    variable += expression[i++];
                }
                i--;
                if (variables.find(variable) != variables.end()) {
                    operands.push(variables[variable]);
                }
                else {
                    std::cout << "";
                }
            }
            else if (expression[i] == '(') {
                operators.push(expression[i]);
            }
            else if (expression[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    char op = operators.top();
                    operators.pop();

                    double b = operands.top();
                    operands.pop();

                    double a = operands.top();
                    operands.pop();

                    operands.push(simpleCalculations::applyOperators(a, b, op));
                }

                if (!operators.empty()) {
                    operators.pop(); // Pop the opening parenthesis
                }
                else {
                    throw std::runtime_error("Mismatched parentheses");
                }
            }
            else if (isOperators(expression[i])) {
                char op = expression[i];

                while (!operators.empty() && precedence[operators.top()] >= precedence[op]) {
                    char topOp = operators.top();
                    operators.pop();

                    double b = operands.top();
                    operands.pop();

                    double a = operands.top();
                    operands.pop();

                    operands.push(simpleCalculations::applyOperators(a, b, topOp));
                }

                operators.push(op);
            }
            else if (expression[i] == 'b') {
                if (i > 0 && !operands.empty()) {
                    double operand = operands.top();
                    operands.pop();
                    int binary = static_cast<int>(operand);
                    operands.push(binary);
                }
                else {
                    throw std::runtime_error("Invalid binary conversion");
                }
            }
            else {
                throw std::runtime_error(&"Invalid character: "[expression[i]]);
            }
        }

        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();

            double b = operands.top();
            operands.pop();

            double a = operands.top();
            operands.pop();

            operands.push(simpleCalculations::applyOperators(a, b, op));
        }

        return operands.top();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error  " << e.what();
    }
   
}
