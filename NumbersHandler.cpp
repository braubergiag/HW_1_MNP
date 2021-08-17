
#include "NumbersHandler.h"


void NumbersHandler::PrintData() const{
    for (const auto & entry: data){
        auto key_pair = entry.first;
        auto data_pair = entry.second;
        std::cout << key_pair.first << " " << key_pair.second << " " << data_pair.first << std::endl;
    }
}
void NumbersHandler::PrintPortData() const{

}
rapidcsv::Document NumbersHandler::ReadDataFromCSV(const std::string & file_path){

    rapidcsv::Document file = rapidcsv::Document (file_path,rapidcsv::LabelParams{},
                              rapidcsv::SeparatorParams{},
                              rapidcsv::ConverterParams{true});
    return file;

}
void NumbersHandler::ParseDataFromCSV(const std::string & file_path) {
    rapidcsv::Document file = ReadDataFromCSV(file_path);
    auto NumberFrom{file.GetColumn<u_int64_t>("NumberFrom")};
    auto NumberTo{file.GetColumn<u_int64_t>("NumberTo")};
    auto OwnerId{file.GetColumn<std::string>("OwnerId")};
    auto RegionCode{file.GetColumn<std::string>("RegionCode")};

    size_t data_size=  file.GetRowCount();
    for (size_t i = 0; i < data_size; ++i){
        auto key_pair = std::make_pair(NumberFrom.at(i),NumberTo.at(i));
        auto value_pair = std::make_pair(OwnerId.at(i),RegionCode.at(i));
        data[key_pair] = value_pair;
    }
}



std::string NumbersHandler::FindOwnerByNumber(u_int64_t phoneNumber) const{

    for (const auto & entry: data){
        auto key_pair = entry.first;
        auto value_pair = entry.second;

        if (phoneNumber >= key_pair.first and phoneNumber <= key_pair.second){
            return  value_pair.first;
        }
    }

    return "Not found.";
}

void NumbersHandler::ParsePortDataFromCSV(const std::string & file_path) {

    io::CSVReader<3> in(file_path);
    io::CSVReader<1> rowIn(file_path);
    rowIn.read_header(io::ignore_extra_column,"RowCount");
    uint32_t data_size;
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
