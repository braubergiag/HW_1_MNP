#include <iostream>
#include <string>
#include "NumbersHandler.h"
#include "csv.h"
#include <fstream>
#include <stdio.h>
#include <time.h>



int main() {

    const std::string file_path = "../Numbering_plan.csv";
    const std::string portFile_path = "../Port_All.csv";

    time_t start, end;
    time(&start);

    uint64_t targetNumber = 9623831218;
    std::string owner;
    NumbersHandler handler;
    handler.ParsePortDataFromCSV(portFile_path);
    handler.ParseDataFromCSV(file_path);
    time(&end);
    double seconds = difftime(end, start);
    std::cout << "Parsing time:" <<  seconds << std::endl;

    time(&start);
    if (handler.FindPortData(targetNumber,owner))
        std::cout << owner << std::endl;
    else if (handler.FindOwnerByNumber(targetNumber,owner)) {
        std::cout << owner << std::endl;
    } else {
        std::cout << "Owner not found." << std::endl;
    }


    time(&end);
    seconds = difftime(end, start);
    std::cout << "Search time:" <<  seconds << seconds << std::endl;


}
