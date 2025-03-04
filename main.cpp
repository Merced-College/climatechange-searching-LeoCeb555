// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <limits> // For std::numeric_limits
#include "StateClimate.h"
#include "BinarySearch.h"

int main() {
    int userFip;
    std::string continueSearch;
    std::vector<StateClimate> climateData;
    std::ifstream file("climdiv_state_year.csv");
    
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int fips, year;
        double temp, tempc;
        char comma;

        ss >> fips >> comma >> year >> comma >> temp >> comma >> tempc;
        climateData.emplace_back(fips, year, temp, tempc);
    }

    file.close();

    //Loop for multiple searches
    while(continueSearch != "No"){
        std::cout << "Enter a state fip number to search: ";
        std::cin >> userFip;

        //Searches for fip number
        BinarySearch bs;
        int val = bs.myBinarySearch(climateData, userFip);

        //Negates any negative numbers and finds lowest instance of fip number
        while (val >= 0 && climateData[val].getFips() == userFip){
            val--;
        }
        val++;

        //Prints each data line that contains fip number until new fip number is found
        while(climateData[val].getFips() == userFip){
        climateData[val].display();
        val++;
        }
        //Asks user if they'd like to continue searching
        std::cout << "Would you like to search for another state fip number? ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, continueSearch);

        //Checks if user input yes or no
        while(continueSearch != "No" && continueSearch != "Yes"){
            std::cout << "Please enter a valid input (Yes/No): ";
            std::getline(std::cin, continueSearch);
        }
    }

    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}
