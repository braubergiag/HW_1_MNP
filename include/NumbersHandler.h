#ifndef HW_1_NUMBERSHANDLER_H
#define HW_1_NUMBERSHANDLER_H
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include "csv.h"
typedef std::pair<uint64_t,uint64_t> range_pair;
class NumbersHandler {
public:
    NumbersHandler(){};
    void PrintData() const;
    void PrintOwners() const;
    void AddOwner(const std::string & owner);
    std::string FindPortData(uint64_t user_number) const;
    std::string FindOwnerByNumber(uint64_t phoneNumber) const;
    void ParseDataFromCSV(const std::string & file_path);
    void ParsePortDataFromCSV(const std::string & file_path);
private:
    std::vector<std::pair<range_pair,uint8_t>> m_owner_data;
    std::vector<std::pair<uint64_t, uint8_t>> m_ported_numbers;
    std::map<std::string,uint8_t> m_owner_to_id;
    std::map<uint8_t,std::string> m_id_to_owner;
};
#endif //HW_1_NUMBERSHANDLER_H
