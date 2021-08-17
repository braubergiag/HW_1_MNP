#include <iostream>
#include <string>
#include "NumbersHandler.h"
#include "csv.h"
#include <fstream>
#include <stdio.h>
#include <time.h>



int main() {

    const std::string file_path = "../Numbering.csv";
    const std::string portFile_path = "../Port_All.csv";

    time_t start, end;

    time(&start);
    NumbersHandler handler;
    handler.ParsePortDataFromCSV(portFile_path);
    time(&end);

    double seconds = difftime(end, start);
    printf("The time: %f seconds\n", seconds);


}
