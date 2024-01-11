#pragma once
#include "mathsFunctions.h"
#include "numbers.h"
#include "ExpressionParser.h"

class evaluateFile  {
 
public:

    //its constructure
    evaluateFile();


    //its destructor 
    ~evaluateFile();

    static void evaluateFromFile(const std::string& filename, std::map<std::string, double>& variables);

private:

    int* resource;

    void initialize();

    void cleanup();
};
      
