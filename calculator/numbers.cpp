
#include <string>
#include "cmath"
#include "numbers.h"
#include <iostream>


int numbers::hexToDecimal(const std::string& expression) {
    try
    {
        return std::stoi(expression, nullptr, 16);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error" << e.what();
    }
   
}

int numbers::binaryToDecimal(const std::string& expression) {

    try
    {
        size_t position = expression.find("b");
        std::string binaryValue = expression.substr(0, position);
        int decimalValue = 0;

        for (int i = binaryValue.length() - 1; i >= 0; i--) {
            if (binaryValue[i] == '1') {
                decimalValue += pow(2, binaryValue.length() - 1 - i);
            }
        }

        return decimalValue;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error" << e.what();
    }
    
}