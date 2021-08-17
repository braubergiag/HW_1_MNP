
#include "NumbersHandler.h"


void NumbersHandler::PrintData() const{
    for (const auto & entry: data){
        auto key_pair = entry.first;
        auto data_pair = entry.second;
        std::cout << key_pair.first << " " << key_pair.second << " " << data_pair.first << std::endl;
    }
}
void NumbersHandler::FindPortData(uint_fast32_t user_number) const{
    uint_fast32_t l = 0,m = 0, r = numbers.size();

    while (r-l > 1) {
        m = (l + r) / 2;
        if (numbers[m].first >= user_number) {
            r = m;
        } else {
            l = m;
        }
    }

    auto & data_pair = numbers[r].second;
    std::cout << numbers[r].first << " " << data_pair.first << " " << data_pair.second << std::endl;

}

void NumbersHandler::ParseDataFromCSV(const std::string & file_path) {

    const int ROWS_COUNT = 4;
    uint32_t data_size;

    io::CSVReader<1> rowsCounter(file_path);
    io::CSVReader<ROWS_COUNT> rowIn(file_path);
    rowsCounter.read_header(io::ignore_extra_column,"RowCount");
    rowsCounter.read_row(data_size);
    rowIn.read_header(io::ignore_extra_column, "NumberFrom", "NumberTo", "OwnerId","RegionCode");


    data.resize(data_size);
    uint_fast32_t numberFrom = 0, numberTo = 0;
    std::string ownerId, regionCode;
    int i = 0;
    while(rowIn.read_row(numberFrom,numberTo,ownerId,regionCode)) {
        auto key_pair = std::make_pair(numberFrom,numberTo);
        auto value_pair = std::make_pair(ownerId,regionCode);
        data[i] = std::make_pair(key_pair,value_pair);
        ++i;
    }
}



std::string NumbersHandler::FindOwnerByNumber(u_int64_t phoneNumber) const{

    uint_fast32_t l = 0,m = 0, r = data.size();
    auto range_min = data[l].first.first;
    auto range_max = data[r - 1].first.second;
    if (phoneNumber < range_min || phoneNumber > range_max) {
        return "Not Found";
    }
    while (r-l > 1) {

        m = (l + r) / 2;
        auto & range = data[m].first;
        if (range.second >= phoneNumber) {
            r = m;
            if (range.first <= phoneNumber) {
                auto & data_entry = data[r].second;
                return data_entry.first;
            }
        } else {
            l = m;
        }
    }

}

void NumbersHandler::ParsePortDataFromCSV(const std::string & file_path) {
    uint32_t data_size;
    const int ROWS_COUNT = 3;
    io::CSVReader<1> rowIn(file_path);
    io::CSVReader<ROWS_COUNT> in(file_path);

    rowIn.read_header(io::ignore_extra_column,"RowCount");

    rowIn.read_row(data_size);
    in.read_header(io::ignore_extra_column, "Number", "OwnerId", "PortDate");
    numbers.resize(data_size);
    uint_fast32_t number = 0;
    std::string owner, date;
    int i = 0;
    while (in.read_row(number, owner, date)) {
        numbers[i].first = number;
        auto & data_entry =  numbers[i].second;
        data_entry.first = owner;
        data_entry.second = date;
        ++i;
    }



};
