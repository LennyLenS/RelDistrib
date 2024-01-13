#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct data{
    std::vector<std::string> fieldNames;
    std::vector<std::string> fieldTypes;
    std::vector<std::vector<std::string>> tuples;
};
struct fileInfo{
    std::vector<std::string> fieldNames;
    std::vector<std::string> fieldTypes;
    int n, m;
};

struct data parse_binary(std::string fileName, int n, int shift);
int binary_txt(std::string fileName);