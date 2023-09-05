/**
 * @file main.cpp
 * @author Sialas Tripp
 * @brief Program that loads data from csv file containing student information about college
 *        into a vector struct and asks user to specify what information they would like to see.
 * @date 2023-08-21
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "analytics.h"
using namespace std;

int main()
{
    vector <GradEmploymentData> empData;
    ifstream inputFile;
    openfile(inputFile);
    readData(empData, inputFile);
    printOutput(empData);
    return 0;
}