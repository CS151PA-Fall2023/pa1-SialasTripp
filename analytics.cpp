/**
 * @file analytics.cpp
 * @author Sialas Tripp
 * @brief Function definition file
 * @date 2023-08-21
 * 
 */

#include "analytics.h"

/**
 * @brief displays menu for user to choose options from
 * 
 */
void displayMenu()
{
    cout << "\n2015 National Survey of Recent College Graduate\n" 
         << "1. Top 10 Majors with the Highest Mean Salary\n" 
         << "2. Top 10 Majors with the Lowest Mean Salary\n"
         << "3. Top 10 Majors with the Highest Median Salary\n"
         << "4. Top 10 Majors with the Lowest Median Salary\n"
         << "5. What are the Top 5 Majors with the Highest Number of Asians\n"
         << "6. What are the Top 5 Majors with the Lowest Number of Asians\n"
         << "7. What are the Top 5 Majors with the Highest Number of Minorities\n"
         << "8. What are the Top 5 Majors with the Lowest Number of Minorities\n"
         << "9. What are the top 3 Majors with the Highest Number of Master Degrees\n"
         << "10. What are the top 3 Majors with the Lowest Number of Master Degrees\n"
         << "11. Display Information for a Specific Major\n"
         << "12. Exit\n"
         << endl
         << "Select a Menu: ";
}

/**
 * @brief Get the Input from user and checks if valid
 * 
 * @return int user input (1-12)
 */
int getInput()
{
    int input;
    cin >> input;
    while(input < 1 || input > 12)
    {
        cout << "Error! Please select number from the list: ";
        cin >> input;
    }
    return input;
}

/**
 * @brief opens file
 * 
 * @param file file that is being opened (graduates2015.csv)
 */
void openfile(ifstream &file)
{
    file.open("graduates2015.csv");
    if (!file)
    {
        cout << "graduates2015.csv";
        exit(1);
    }
}

/**
 * @brief scrubs data from csv file so that it can be read into that vector struct that
 *        contains all relevent information.
 * 
 * @param data vector of struct information is being loaded into
 * @param file csv file that gets read
 */
void readData(vector<GradEmploymentData> &data, ifstream &file)
{
    string first;
    GradEmploymentData temp;
    getline(file, first);
    while(file.peek() != EOF)
    {
        char delim;
        file >> temp.demographicsTotal >> delim;
      
        if (file.peek() == '"')
        {
            file >> delim;
            getline(file, temp.educationMajor, '"');
            file >> delim;
        }
        else
        {
            getline(file, temp.educationMajor, ',');
        }
        file >> temp.meanSalary >> delim;
        file >> temp.medianSalary >> delim;
        file >> temp.demographicsAsian >> delim;
        file >> temp.demographicsMinority >> delim;
        file >> temp.demographicsWhite >> delim;
        file >> temp.demographicsFemales >> delim;
        file >> temp.demographicsMales >> delim;
        file >> temp.educationBachelor >> delim;
        file >> temp.educationDoctorate >> delim;
        file >> temp.educationMasters >> delim;
        data.push_back(temp);
    }
}

/**
 * @brief loop that prints output depending on user choice
 * 
 * @param data vector of struct that will be passed to functions 
 */
void printOutput(vector<GradEmploymentData> &data)
{
    while(1)
    {
        displayMenu();
        int choice = getInput();
    
        switch (choice)
        {
            case 1:
            {
                highMean(data);
                pressEnter();

            } 
            break;
            case 2:
            {
                lowMean(data);
                pressEnter();
            }
            break;
            case 3:
            {
                highMed(data);
                pressEnter();
            }
            break;
            case 4:
            {
                lowMed(data);
                pressEnter();
            }
            break;
            case 5:
            {
                topAsian(data);
                pressEnter();
            }
            break;
            case 6:
            {
                lowAsian(data);
                pressEnter();
            }
            break;
            case 7:
            {
                highMinor(data);
                pressEnter();
            }
            break;
            case 8:
            {
                lowMinor(data);
                pressEnter();
            }
            break;
            case 9:
            {
                highMaster(data);
                pressEnter();
            }
            break;
            case 10:
            {
                lowMaster(data);
                pressEnter();
            }
            break;
            case 11:
            {
                sortMajor(data);
                for(size_t i =0; i<data.size(); i++)
                {
                    cout << i +1 << ". " << data[i].educationMajor << endl;
                }
                int input;
                cout <<"\nEnter a Major: ";
                cin >> input;
                while(input < 1 || input > 45)
                {
                    cout << "Error! Please select number from the list: ";
                    cin >> input;
                }
                displayMajor(data, input);
                pressEnter();
            }
            break;
            case 12:
            {
                exit(1);
            }
            break;
        }
    }
}

/**
 * @brief finds the highest 10 mean salary majors of graduates and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void highMean(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].meanSalary < temp.meanSalary) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Mean Salary\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<10; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << setw(3) << "$" << right 
             << setw(9) << setprecision(2) << fixed << data[i].meanSalary << endl;
    }
}

/**
 * @brief finds the lowest 10 mean salary majors of graduates and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void lowMean(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].meanSalary > temp.meanSalary) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Mean Salary\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<10; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << setw(3) << "$" << right 
             << setw(9) << setprecision(2) << fixed << data[i].meanSalary << endl;
    }
}

/**
 * @brief finds the highest 10 median salary majors of graduates and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void highMed(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].medianSalary < temp.medianSalary) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Median Salary\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<10; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << setw(3) << "$" << right 
             << setw(9) << setprecision(2) << fixed << data[i].medianSalary << endl;
    }  
}

/**
 * @brief finds the lowest 10 median salary majors of graduates and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void lowMed(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].medianSalary > temp.medianSalary) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Median Salary\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<10; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << setw(3) << "$" << right 
             << setw(9) << setprecision(2) << fixed << data[i].medianSalary << endl;
    }  
}

/**
 * @brief finds the top 5 majors with an asian demographic and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void topAsian(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].demographicsAsian < temp.demographicsAsian) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Number of Asians\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<5; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].demographicsAsian << endl;
    } 
}

/**
 * @brief finds the lowest 5 majors with an asian demographic and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void lowAsian(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].demographicsAsian > temp.demographicsAsian) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Number of Asians\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<5; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].demographicsAsian << endl;
    } 
}

/**
 * @brief finds the top 5 majors with a minority demographic and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void highMinor(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].demographicsMinority < temp.demographicsMinority) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Number of Minorities\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<5; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].demographicsMinority << endl;
    } 
}

/**
 * @brief finds the lowest 5 majors with a minority demographic and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void lowMinor(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].demographicsMinority > temp.demographicsMinority) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Number of Minorities\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<5; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].demographicsMinority << endl;
    } 
}

/**
 * @brief finds the top 3 majors with masters degrees and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void highMaster(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].educationMasters < temp.educationMasters) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Masters Degree\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<3; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].educationMasters << endl;
    } 
}

/**
 * @brief finds the lowest 3 majors with masters degrees and displays it
 * 
 * @param data vector struct that contains relevent data
 */
void lowMaster(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].educationMasters > temp.educationMasters) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }

    cout << "Education Major                    Masters Degree\n";
    cout << "------------------------------------------------\n";
    for(int i =0; i<3; i++)
    {
        cout << left << setw(34) << data[i].educationMajor << right 
             << setw(9) << setprecision(2) << fixed << data[i].educationMasters << endl;
    } 
}

/**
 * @brief sorts the major aplhabetically using insertion sort
 * 
 * @param data vector struct that contains relevent data
 */
void sortMajor(vector<GradEmploymentData> &data)
{
    for (size_t i = 1; i < data.size(); ++i) 
     {
        GradEmploymentData temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].educationMajor > temp.educationMajor) 
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

/**
 * @brief displays the major selected by user and all relevant data for said major
 * 
 * @param data vector struct that contains relevent data
 * @param input user input for choice of major they'd like more information on
 */
void displayMajor(vector<GradEmploymentData> &data, int input)
{
    for (size_t i = 0; i < data.size(); ++i) 
    {
        int check = i;
        if((check+1) == input)
        {
            cout << left << "Major: "<<  right << setw(39) << data[i].educationMajor << endl
                << left << setw(34) << "Mean Salary: "<< setw(3) << "$" << right 
                << setw(9) << setprecision(2) << fixed << data[i].meanSalary << endl
                << left << setw(34) << "Median Salary: " << setw(3) << "$" << right 
                << setw(9) << setprecision(2) << fixed << data[i].medianSalary << endl
                << left << setw(34) << "Asian Demographic: " << right << setw(12) << data[i].demographicsAsian << endl
                << left << setw(34) << "Minority Demographic: " << right << setw(12) << data[i].demographicsMinority << endl
                << left << setw(34) << "White Demographic: " << right << setw(12) << data[i].demographicsWhite << endl
                << left << setw(34) << "Female Demographic: " << right << setw(12) << data[i].demographicsFemales << endl
                << left << setw(34) << "Male Demographic: " << right << setw(12) << data[i].demographicsMales << endl
                << left << setw(34) << "Bachelor Degrees: " << right << setw(12) << data[i].educationBachelor << endl
                << left << setw(34) << "Doctorate Degrees: " << right << setw(12) << data[i].educationDoctorate << endl
                << left << setw(34) << "Masters Degree: " << right << setw(12) << data[i].educationMasters << endl;
        }

    }

}

/**
 * @brief simple function that asks user to press enter to continue
 * 
 */
void pressEnter()
{
    cout << "\nPress enter to contine... ";
    cin.ignore();
    cin.get();
}