#include "binary_parser.h"
#include <iostream>

using namespace std;

std::vector<struct data> parse_binary(std::string fileName){
    std::vector<struct data> data;
    FILE *f; 
    f = fopen("authors.bin", "rb");
    // std::ifstream rf("student.dat", ios::out | ios::binary);
    // if(!rf) {
    //     cout << "Cannot open file!" << endl;
    //     return {};
    // }
    int n = 0, m = 0;
    fread(&n, sizeof(int), 1, f);
    fread(&m, sizeof(int), 1, f);
    for(int i = 0; i < m; ++i){
        string buf;
        buf.resize(256);
        fread(&buf, 256, 1, f);
        data.fieldNames.push_back(buf);
    }

    std::vector<int> columnSizes;
    for(int i = 0; i < m; ++i){
        int buf = 0;
        fread(&buf, sizeof(int), 1, f);
        columnSizes.push_back(buf);
    }

    std::vector<int> columnType;
    for(int i = 0; i < m; ++i){
        string buf;
        buf.resize(256);
        fread(&buf, 256, 1, f);
        columnType.push_back(buf);
    }

    for(int i = 0; i < n; ++i){
        data.push_back({});
        for(int j = 0; j < m; ++j){
            if(columnType[i] == "int"){
                int buf = 0;
                fread(&buf, sizeof(int), 1, f);
                data[i].push_back(std::to_string(buf));
            }else if(columnType[i] == "string"){
                string buf;
                buf.resize(256);
                fread(&buf, 256, 1, f);
                data[i].push_back(buf);
            }else{
                bool buf = true;
                fread(&buf, sizeof(bool), 1, f);
                data[i].push_back(std::to_string(buf));
            }
            
        }
    }
    return data;
}
