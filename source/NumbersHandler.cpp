
#include "../include/NumbersHandler.h"



void NumbersHandler::PrintData() const{
    for (const auto & entry: m_owner_data){
        auto key_pair = entry.first;
        auto ownerId = entry.second;
        std::cout << key_pair.first << " " << key_pair.second << " " << m_id_to_owner.at(ownerId) << std::endl;
    }
}

std::string NumbersHandler::FindPortData(uint64_t user_number) const{
    int64_t l = - 1,m = 0, r = m_ported_numbers.size() - 1;
    if (user_number < m_ported_numbers[l + 1].first || user_number > m_ported_numbers[r].first) {
        return "";
    }
    while (r-l > 1) {
        m = (l + r) / 2;
        if (m_ported_numbers[m].first >= user_number) {
            r = m;
        } else {
            l = m;
        }
    }
    if (user_number == m_ported_numbers[r].first) {
        std::string owner = m_id_to_owner.at(m_ported_numbers[r].second);
        return owner;
    } else {
        return "";
    }

}
std::string NumbersHandler::FindOwnerByNumber(uint64_t phoneNumber) const{
    //   (l,r]
    int64_t l = -1,m = 0, r = m_owner_data.size() - 1;
    auto range_min = m_owner_data[l + 1].first.first;
    auto range_max = m_owner_data[r].first.second;
    if (phoneNumber < range_min || phoneNumber > range_max) {
        return "";
    }
    while (r-l > 1) {

        m = (l + r) / 2;
        auto & range = m_owner_data[m].first;
        if (range.second >= phoneNumber) {
            r = m;
            if (range.first <= phoneNumber) {
                std::string owner = m_id_to_owner.at(m_owner_data[r].second);
                return owner;
            }
        } else {
            l = m;
        }
    }
    return "";

}

void NumbersHandler::ParsePortDataFromCSV(const std::string & file_path) {
    uint32_t data_size = 0;
    const int ROWS_COUNT = 2;
    io::CSVReader<1> rowIn(file_path);
    io::CSVReader<ROWS_COUNT> in(file_path);

    rowIn.read_header(io::ignore_extra_column,"RowCount");

    rowIn.read_row(data_size);
    in.read_header(io::ignore_extra_column, "Number", "OwnerId");
    m_ported_numbers.resize(data_size);
    uint64_t number = 0;
    std::string owner;
    size_t i = 0;
    while (in.read_row(number, owner)) {
        AddOwner(owner);
        m_ported_numbers[i].first = number;
        m_ported_numbers[i].second = m_owner_to_id[owner];
        ++i;


    }



};
void NumbersHandler::ParseDataFromCSV(const std::string & file_path) {

    const int ROWS_COUNT = 3;
    uint32_t data_size = 0;

    io::CSVReader<1> rowsCounter(file_path);
    io::CSVReader<ROWS_COUNT> rowIn(file_path);
    rowsCounter.read_header(io::ignore_extra_column,"RowCount");
    rowsCounter.read_row(data_size);
    rowIn.read_header(io::ignore_extra_column, "NumberFrom", "NumberTo", "OwnerId");

    m_owner_data.resize(data_size);
    uint64_t numberFrom = 0, numberTo = 0;
    std::string owner;
    size_t i = 0;

    while(rowIn.read_row(numberFrom,numberTo,owner)) {
        AddOwner(owner);
        m_owner_data[i].first =  std::make_pair(numberFrom, numberTo);
        m_owner_data[i].second =  m_owner_to_id[owner];
        ++i;
    }
}

void NumbersHandler::PrintOwners() const {
    for (const auto & item: m_owner_to_id){
        std::cout << item.first << " " << item.second << std::endl;
    }

}

void NumbersHandler::AddOwner(const std::string &owner) {
    if (m_owner_to_id.count(owner) == 0) {
        m_owner_to_id[owner] = m_owner_to_id.size();
        m_id_to_owner[m_id_to_owner.size()] = owner;
    }

}


