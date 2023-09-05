/**
 * @file analytics.h
 * @author Sialas Tripp
 * @brief Header file
 * @date 2023-08-21
 * 
 */

#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void displayMenu();
int getInput();
void pressEnter();
void printOutput(vector<GradEmploymentData> &data);
void highMean(vector<GradEmploymentData> &data);
void lowMean(vector<GradEmploymentData> &data);
void highMed(vector<GradEmploymentData> &data);
void lowMed(vector<GradEmploymentData> &data);
void topAsian(vector<GradEmploymentData> &data);
void lowAsian(vector<GradEmploymentData> &data);
void highMinor(vector<GradEmploymentData> &data);
void lowMinor(vector<GradEmploymentData> &data);
void highMaster(vector<GradEmploymentData> &data);
void lowMaster(vector<GradEmploymentData> &data);
void sortMajor(vector<GradEmploymentData> &data);
void displayMajor(vector<GradEmploymentData> &data, int input);
void openfile(ifstream &file);
void readData(vector<GradEmploymentData> &data, ifstream &file);
void addMajorToVector(vector<GradEmploymentData> &data, string line);



#endif // ANALYTICS_H