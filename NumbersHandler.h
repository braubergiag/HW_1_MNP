//
// Created by marshall on 19.07.2021.
//

#ifndef HW_1_NUMBERSHANDLER_H
#define HW_1_NUMBERSHANDLER_H
#include <utility>
#include <map>
#include <vector>
#include <string>
#include "rapidcsv.h"
typedef std::pair<u_int64_t,u_int64_t> range_pair;
typedef std::pair<std::string,std::string> data_pair;

class NumbersHandler {
public:
    NumbersHandler(const std::string & file_path_);
    void PrintData() const;
    std::string FindOwnerByNumber(const u_int64_t phoneNumber) const;
private:

    void ReadDataFromCSV();
    void ParseDataFromCSV();


    std::string file_path;
    rapidcsv::Document file;
    std::map<range_pair,data_pair> data;
    size_t data_size;
};


#endif //HW_1_NUMBERSHANDLER_H
