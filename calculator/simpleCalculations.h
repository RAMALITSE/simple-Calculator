#pragma once
#include <iostream>

class simpleCalculations {

    // Helper functions
    void initialize();

    void cleanup();


public:
    

    simpleCalculations();
    ~simpleCalculations();

    static double applyOperators(double a, double b, char op);
};


