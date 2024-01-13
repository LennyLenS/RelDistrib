#include "binary_parser.h"

std::string convertStr(std::string str) {
    int pos = 0;
    for (int j = 0; j < 256; j++) {
        if (str[j] == ' ' && str[j + 1] == ' ') {
            pos = j;
            break;
        }
    }

    str.erase(pos);
    return str; 
}

struct fileInfo file_info(std::string fileName){
    std::ifstream Fin;         
    Fin.open(fileName, std::ios::binary);
    struct fileInfo data;
    Fin.read((char*)&(data.n), sizeof(int));
    Fin.read((char*)&(data.m), sizeof(int));
    for(int i = 0; i < data.m; ++i){
        char * buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldNames.push_back(bufString);
    }

    for(int i = 0; i < data.m; ++i){
        char * buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldTypes.push_back(convertStr(bufString));
    }
    Fin.close();
    return data;
}

int get_turple_size(std::string fileName){
    auto fileInfo = file_info(fileName);
    int ans = 0;
    for(auto type: fileInfo.fieldTypes){
        if(type == "int"){
            ans += (int)sizeof(int);
        }else if(type == "bool"){
            ans += (int)sizeof(bool);
        }else{
            ans += 256;
        }
    }
    return ans;
}

struct data parse_binary(std::string fileName, int shift = 0, int quantity = 10) {
    std::ifstream Fin;         
    Fin.open(fileName, std::ios::binary);
    struct data data;

    int n = 0, m = 0;
    Fin.read((char*)&n, sizeof(int));
    Fin.read((char*)&m, sizeof(int));

    for(int i = 0; i < m; ++i){
        char * buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldNames.push_back(bufString);
    }

    std::vector<std::string> fieldTypes = {};
    for(int i = 0; i < m; ++i){
        char * buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldTypes.push_back(bufString);
        fieldTypes.push_back(convertStr(bufString));
    }

    Fin.seekg(Fin.tellg() + (long long)shift);
    for(int i = 0; i < quantity; ++i){
        data.tuples.push_back({});
        for(int j = 0; j < m; ++j){
            if(fieldTypes[j] == "int"){
                int buf = 0;
                Fin.read((char*)&buf, sizeof(int));
                data.tuples[i].push_back(std::to_string(buf));
            }else if(fieldTypes[j] == "char(256)"){
                char * buf = new char[256];        
                Fin.read(buf, 256);
                std::string bufString = buf;                       
                delete[]buf;
                data.tuples[i].push_back(bufString);
            }else{
                bool buf = true;
                Fin.read((char *)&buf, sizeof(bool));
                data.tuples[i].push_back(std::to_string(buf));
            }
        }
    }

    Fin.close();
    return data;
}


int binary_txt(std::string fileName) {
    std::cout << fileName << ":\n";
    auto data = parse_binary(fileName, get_turple_size(fileName) * 3);
    fileName.erase(fileName.length() - 4);
    std::ofstream fOut;         
    fOut.open(fileName + ".txt");   

    int n = data.tuples.size(); 
    int m = data.fieldNames.size();

    fOut << n << " " << m << std::endl;

    std::string str = "";
    for (int i = 0; i < m; i++) {
        str = convertStr(data.fieldNames[i]);
        fOut << str << " ";
    }
    fOut << std::endl;

    std::vector<std::string> fieldTypes = {};
    for (int i = 0; i < m; i++) {
        str = convertStr(data.fieldTypes[i]);
        fieldTypes.push_back(str);

        fOut << str << " ";
    }
    fOut << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            str = data.tuples[i][j];
            if (fieldTypes[j] == "char(256)") {
                str = convertStr(str);
            }

            fOut << str << " ";
        }
        fOut << std::endl;
    }
    fOut << std::endl;

    fOut.close();
    return 0;
}
