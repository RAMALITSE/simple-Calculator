
#include <regex>
#include <map>
#include "cmath"
#include "mathsFunctions.h"
#include <string>


// we want to take ^ as it is and the convert to power (pow)
std::string baf;
void replacePowerOperator() {
    size_t pos = baf.find('^');
    while (pos != std::string::npos) {
        baf.replace(pos, 1, "pow(");
        pos = baf.find('^', pos + 4); 
        baf.insert(pos + 1, ")");
    }
}

double mathsFunctions::evaluateTrigFunction(const std::string& expression, std::map<std::string, double>& variables) {
    std::regex pattern("([a-z]+)\\(([\\d\\.]+)\\)");

    try
    {
        std::smatch match;


        if (regex_match(expression, match, pattern)) {
            std::string trigFunction = match[1];
            double argument = stod(match[2]);

            if (trigFunction == "sin") {
                return sin(argument);
            }
            else if (trigFunction == "cos") {
                return round(cos(argument));
            }
            else if (trigFunction == "tan") {
                return tan(argument);
            }
            else {
                replacePowerOperator();

                throw std::runtime_error("Invalid trigonometric function: ");
            }
        }
    }
    catch (const std::exception& error)
    {
        throw std::runtime_error(error.what());
    }

 
}


