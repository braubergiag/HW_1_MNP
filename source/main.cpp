#include <iostream>
#include "NumbersHandler.h"
#include <time.h>



int main() {

    const std::string file_path = "../data/Numbering_plan.csv";
    const std::string portFile_path = "../data/Port_All.csv";

    time_t start, end;
    time(&start);

    std::vector<uint64_t> targetNumbersTest = {9000000000,
            9023271696,
            9036540285,
            9030065036,
            9022673390,
            9022673237,
            9036540240,
            9000000023,
            9023271696,
            9036540285,
            9030065036,
            9022673390,
            9022673237,
            9036540240,
    };
    std::string owner;
    NumbersHandler handler;
    time(&start);
    handler.ParsePortDataFromCSV(portFile_path);
    handler.ParseDataFromCSV(file_path);

    for (auto & targetNumber:targetNumbersTest){
        if (handler.FindPortData(targetNumber,owner))
            std::cout << owner << std::endl;
        else if (handler.FindOwnerByNumber(targetNumber,owner)) {
            std::cout << owner << std::endl;
        } else {
            std::cout << "Owner not found." << std::endl;
        }
    }



    time(&end);
    double seconds = difftime(end, start);
    std::cout << "Time:" <<  seconds  << " seconds" <<  std::endl;



}
