
#include "../include/NumbersHandler.h"


void NumbersHandler::PrintData() const{
    for (const auto & entry: owner_data){
        auto key_pair = entry.first;
        auto data_pair = entry.second;
        std::cout << key_pair.first << " " << key_pair.second << " " << data_pair.first << std::endl;
    }
}
bool NumbersHandler::FindPortData(uint64_t user_number,std::string &owner) const{
    int64_t l = - 1,m = 0, r = ported_numbers.size() - 1;
    if (user_number < ported_numbers[l + 1].first || user_number > ported_numbers[r].first) {
        return false;
    }
    while (r-l > 1) {
        m = (l + r) / 2;
        if (ported_numbers[m].first >= user_number) {
            r = m;
        } else {
            l = m;
        }
    }
    if (user_number == ported_numbers[r].first) {
        owner = ported_numbers[r].second;
        return true;
    } else {
        return false;
    }

}
bool NumbersHandler::FindOwnerByNumber(uint64_t phoneNumber,std::string &owner) const{
    //   (l,r]
    int64_t l = -1,m = 0, r = owner_data.size() - 1;
    auto range_min = owner_data[l + 1].first.first;
    auto range_max = owner_data[r].first.second;
    if (phoneNumber < range_min || phoneNumber > range_max) {
        return false;
    }
    while (r-l > 1) {

        m = (l + r) / 2;
        auto & range = owner_data[m].first;
        if (range.second >= phoneNumber) {
            r = m;
            if (range.first <= phoneNumber) {
                auto & data_entry = owner_data[r].second;
                owner = data_entry.first;
                return true;
            }
        } else {
            l = m;
        }
    }
    return false;

}

void NumbersHandler::ParsePortDataFromCSV(const std::string & file_path) {
    uint32_t data_size;
    const int ROWS_COUNT = 2;
    io::CSVReader<1> rowIn(file_path);
    io::CSVReader<ROWS_COUNT> in(file_path);

    rowIn.read_header(io::ignore_extra_column,"RowCount");

    rowIn.read_row(data_size);
    in.read_header(io::ignore_extra_column, "Number", "OwnerId");
    ported_numbers.resize(data_size);
    uint_fast32_t number = 0;
    std::string owner;
    size_t i = 0;
    while (in.read_row(number, owner)) {
        auto pair = std::make_pair(number,owner);
        ported_numbers[i].first = number;
        ported_numbers[i].second = owner;
        ++i;


    }



};
void NumbersHandler::ParseDataFromCSV(const std::string & file_path) {

    const int ROWS_COUNT = 4;
    uint32_t data_size;

    io::CSVReader<1> rowsCounter(file_path);
    io::CSVReader<ROWS_COUNT> rowIn(file_path);
    rowsCounter.read_header(io::ignore_extra_column,"RowCount");
    rowsCounter.read_row(data_size);
    rowIn.read_header(io::ignore_extra_column, "NumberFrom", "NumberTo", "OwnerId","RegionCode");


    owner_data.resize(data_size);
    uint_fast32_t numberFrom = 0, numberTo = 0;
    std::string ownerId, regionCode;
    size_t i = 0;

    while(rowIn.read_row(numberFrom,numberTo,ownerId,regionCode)) {

        auto key_pair = std::make_pair(numberFrom,numberTo);
        auto value_pair = std::make_pair(ownerId,regionCode);
        owner_data[i++] = std::make_pair(key_pair, value_pair);
    }
}


