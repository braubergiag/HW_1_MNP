#include <iostream>
#include <string>
#include "NumbersHandler.h"


int main() {
    const std::string file_path = "../Numbering.csv";
    NumbersHandler numbers(file_path);
    std::cout << numbers.FindOwnerByNumber(9623831218);


}
