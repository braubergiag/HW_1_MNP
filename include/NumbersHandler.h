//
// Created by marshall on 19.07.2021.
//

#ifndef HW_1_NUMBERSHANDLER_H
#define HW_1_NUMBERSHANDLER_H
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "csv.h"

typedef std::pair<uint64_t,uint64_t> range_pair;
typedef std::pair<std::string,std::string> data_pair;


class NumbersHandler {
public:
    NumbersHandler(){};
    void PrintData() const;
    void PrintOwners() const;
    void AddOwner(const std::string & owner);
    bool FindPortData(uint64_t user_number,std::string &owner) const;
    bool FindOwnerByNumber(uint64_t phoneNumber,std::string &owner) const;
    void ParseDataFromCSV(const std::string & file_path);
    void ParsePortDataFromCSV(const std::string & file_path);
private:
    std::vector<std::pair<range_pair,data_pair>> owner_data;
    std::vector<std::pair<uint_fast32_t, uint8_t>> ported_numbers;
    std::map<std::string,uint8_t> ownerToId;
    std::map<uint8_t,std::string> IdToOwner;



};


#endif //HW_1_NUMBERSHANDLER_H
