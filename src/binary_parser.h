#include <iostream>
#include <vector>
#include <string>

struct data{
    std::vector<string> vec;
    std::vector<string> fieldNames;
};

std::vector<struct data> parse_binary(std::string fileName);