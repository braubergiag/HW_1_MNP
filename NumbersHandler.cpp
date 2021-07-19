
#include "NumbersHandler.h"

NumbersHandler::NumbersHandler(const std::string &file_path_) :file_path(file_path_){

    ReadDataFromCSV();
    ParseDataFromCSV();
};
void NumbersHandler::PrintData() const{
    for (const auto & entry: data){
        auto key_pair = entry.first;
        auto data_pair = entry.second;
        std::cout << key_pair.first << " " << key_pair.second << " " << data_pair.first << std::endl;
    }
}
void NumbersHandler::ReadDataFromCSV(){

    file = rapidcsv::Document (file_path,rapidcsv::LabelParams{},
                              rapidcsv::SeparatorParams{},
                              rapidcsv::ConverterParams{true});
    data_size = file.GetRowCount();

}
void NumbersHandler::ParseDataFromCSV() {
    auto NumberFrom{file.GetColumn<u_int64_t>("NumberFrom")};
    auto NumberTo{file.GetColumn<u_int64_t>("NumberTo")};
    auto OwnerId{file.GetColumn<std::string>("OwnerId")};
    auto RegionCode{file.GetColumn<std::string>("RegionCode")};


    for (int i = 0; i < data_size; ++i){
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
};