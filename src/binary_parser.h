#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct fileInfo {
    std::vector<std::string> fieldNames;
    std::vector<std::string> fieldTypes;
    int n, m, tuple_size;
};

struct data {
    struct fileInfo* info;
    std::vector<std::vector<std::string>> tuples;

    public:

        data() {
            this->info = nullptr;
        }

        ~data() {
            delete this->info;
        }
};

int getFileInfo(std::string fileName, struct data& data);
int parseBinary(std::string fileName, struct data& data, int shift = 0, int quantity = -1);
int binaryTxt(std::string fileName);
std::string convertStr(std::string str);