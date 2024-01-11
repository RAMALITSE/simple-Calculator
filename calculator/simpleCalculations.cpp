#include <stdexcept>
#include "cmath"
#include "simpleCalculations.h"



    void simpleCalculations::initialize()
    {
    }

    void simpleCalculations::cleanup()
    {
    }

  

    double simpleCalculations::applyOperators(double a, double b, char op) {
        switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            throw std::runtime_error("Invalid operator");
        }
    }


    simpleCalculations::simpleCalculations()
    {
        initialize();

    }

    simpleCalculations::~simpleCalculations() {

        cleanup();
    }
