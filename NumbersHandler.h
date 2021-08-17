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




class NumbersHandler {
public:
    NumbersHandler(){};
    void PrintData() const;
    void FindPortData(uint_fast32_t user_number) const;
    std::string FindOwnerByNumber(const u_int64_t phoneNumber) const;
    void ParseDataFromCSV(const std::string & file_path);
    void ParsePortDataFromCSV(const std::string & file_path);
private:




    std::vector<std::pair<range_pair,data_pair>> data;
    std::vector<std::pair<int_fast32_t,data_pair>> numbers;

};


#endif //HW_1_NUMBERSHANDLER_H
