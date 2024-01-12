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

struct data parse_binary(std::string fileName) {

    struct data data;
    FILE *f; 
    f = fopen(fileName.c_str(), "rb");
    
    int n = 0, m = 0;
    fread(&n, sizeof(int), 1, f);
    fread(&m, sizeof(int), 1, f);
    for(int i = 0; i < m; ++i){
        char * buf = new char[256];        
        fread(buf, 256, 1, f);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldNames.push_back(bufString);
    }

    std::vector<std::string> fieldTypes = {};
    for(int i = 0; i < m; ++i){
        char * buf = new char[256];        
        fread(buf, 256, 1, f);
        std::string bufString = buf;                       
        delete[]buf;
        data.fieldTypes.push_back(bufString);
        fieldTypes.push_back(convertStr(bufString));
    }


    for(int i = 0; i < n; ++i){
        data.tuples.push_back({});
        for(int j = 0; j < m; ++j){
            if(fieldTypes[j] == "int"){
                int buf = 0;
                fread(&buf, sizeof(int), 1, f);
                data.tuples[i].push_back(std::to_string(buf));
            }else if(fieldTypes[j] == "char(256)"){
                char * buf = new char[256];        
                fread(buf, 256, 1, f);
                std::string bufString = buf;                       
                delete[]buf;
                data.tuples[i].push_back(bufString);
            }else{
                bool buf = true;
                fread(&buf, sizeof(bool), 1, f);
                data.tuples[i].push_back(std::to_string(buf));
            }
            
        }
    }

    fclose(f);
    return data;
}


int binary_txt(std::string fileName) {
    auto data = parse_binary(fileName);

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
