// cal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "evaluateFile.h"

int main() {

    std::string filename;
    std::map<std::string, double> input;

    evaluateFile fileEvaluator;

    while (true) {

        std::cout << "Enter File Name\n";

        std::cin >> filename;
        std::string fullFilename = (filename.find('.') == std::string::npos) ? filename + ".txt" : filename;

        fileEvaluator.evaluateFromFile(fullFilename, input);
        
    }

    std::cout << "Thank you for using our calculator." << std::endl;

    fileEvaluator.~evaluateFile();

    return 0;

    system("PAUSE");
}

    
