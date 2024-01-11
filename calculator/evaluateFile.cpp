
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "evaluateFile.h"
#include "mathsFunctions.h"
#include "numbers.h"
#include "ExpressionParser.h"
#include <exception>



//my constructor
evaluateFile::evaluateFile() {
           initialize();
}

//my destructor
evaluateFile::~evaluateFile() {
          cleanup();
}
ExpressionParser expressionParser;



void evaluateFile::evaluateFromFile(const std::string& filename, std::map<std::string, double>& variables)  {
    std::ifstream inputFile(filename);


    try
    {
        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl;
            return;
        }

        std::string expression;
        while (getline(inputFile, expression)) {
            std::string line;
            
                try {
                 
                    if (expression.find('=') != std::string::npos) {

                        try
                        {
                            size_t position = expression.find('=');
                            std::string variableName = expression.substr(0, position);
                            std::string variableValue = expression.substr(position + 1);
                            variables[variableName] = stod(variableValue);
                            std::cout << variableValue << std::endl;
                        }
                        catch (const std::exception& w)
                        {
                            std::cout << "Error"<< w.what();
                        }
                      

                    }
                    else if (expression == "variables") {
                        if (variables.empty()) {
                            std::cout << "No variables defined." << std::endl;
                        }
                        else {
                            for (const auto& variable : variables) {
                                 std::cout << variable.first << " = " << variable.second << std::endl;
                            }
                        }

                    }
                    else if (expression.find("sin") != std::string::npos || expression.find("cos") != std::string::npos ||
                           expression.find("tan") != std::string::npos) {

                        //function calling from function class
                        double result = mathsFunctions::evaluateTrigFunction(expression, variables);
                        std::cout << result << std::endl;

                    }
                    else if (expression.find("0x") == 0) {

                        //calling function to convert  hexstring to decimal in number class
                        int decimalValue = numbers::hexToDecimal(expression);
                        std::cout << decimalValue << std::endl;

                    }
                    else if (expression.find("b") != std::string::npos) {

                        //calling function to convert binary to decimal from number class
                        int decimalValue = numbers::binaryToDecimal(expression);
                        std::cout << decimalValue << std::endl;
                    }
                    else {
                        
                        double result = expressionParser.evaluateExpression(expression, variables);
                        std::cout << result << std::endl;
                    }
                }
                catch (const std::runtime_error& error) {
                    std::cerr << "Error: " << error.what() << std::endl;
                }
           
        }

        if (inputFile.bad()) {
            std::cerr << "Error: Failed to read the entire file." << std::endl;
        }

        inputFile.close();
    }
    catch (const std::exception& e)
    {
        std::cout << "Error " << e.what();
    }
   
  
}

void evaluateFile::initialize()
{
     resource = new int[10];
}

void evaluateFile::cleanup()
{
    delete[] resource;
}
