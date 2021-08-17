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
#include "csv.h"
typedef std::pair<u_int64_t,u_int64_t> range_pair;
typedef std::pair<std::string,std::string> data_pair;


struct PortData {
    PortData(){};
    PortData(const std::vector<uint_fast32_t>& numbers_,
             const std::vector<std::string>& ownerId_,
             const std::vector<std::string>& portData_):
             numbers(numbers_),ownerId(ownerId_),portData(portData_){};
    std::vector<uint_fast32_t> numbers;
    std::vector<std::string> ownerId;
    std::vector<std::string> portData;
};


class NumbersHandler {
public:
    NumbersHandler(){};
    void PrintData() const;
    void PrintPortData() const;
    std::string FindOwnerByNumber(const u_int64_t phoneNumber) const;
    void ParseDataFromCSV(const std::string & file_path);
    void ParsePortDataFromCSV(const std::string & file_path);
private:

    rapidcsv::Document ReadDataFromCSV(const std::string & file_path);




    std::map<range_pair,data_pair> data;

    std::vector<std::pair<int_fast32_t,data_pair>> numbers;

};


#endif //HW_1_NUMBERSHANDLER_H
