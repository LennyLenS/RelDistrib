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

int getFileInfo(std::string fileName, struct data& data) {
    std::ifstream Fin;      
    Fin.open(fileName, std::ios::binary);

    delete data.info;
    data.info = new struct fileInfo;

    int n = 0;
    int m = 0;

    Fin.read((char*)&(n), sizeof(int));
    Fin.read((char*)&(m), sizeof(int));
    data.info->n = n;
    data.info->m = m;

    for (int i = 0; i < m; ++i) {
        char* buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[] buf;
        data.info->fieldNames.push_back(bufString);
    }

    data.info->tuple_size = 0;
    for (int i = 0; i < m; ++i) {
        char* buf = new char[256];        
        Fin.read(buf, 256);
        std::string bufString = buf;                       
        delete[] buf;
        std::string bufType = convertStr(bufString);
        data.info->fieldTypes.push_back(bufType);

        if (bufType == "int") {
            data.info->tuple_size += sizeof(int);

        } else if (bufType == "char(256)") {
            data.info->tuple_size += 256;

        } else {
            data.info->tuple_size += sizeof(bool);
        }
    }

    Fin.close();
    return 0;
}

int parseBinary(std::string fileName, struct data& data, int shift, int quantity) {
    std::ifstream Fin;         
    Fin.open(fileName, std::ios::binary);

    if (!(data.info)) {
        getFileInfo(fileName, data);
    }

    int buf = 2 * sizeof(int) + 2 * data.info->m * 256 + shift * data.info->tuple_size;
    Fin.seekg(Fin.tellg() + (long) buf);

    int n = data.info->n;
    int m = data.info->m;

    if (quantity == -1) {
        quantity = n - shift;
    }

    for (int i = 0; i < quantity; ++i) {
        data.tuples.push_back({});
        for (int j = 0; j < m; ++j) {
            if (data.info->fieldTypes[j] == "int") {
                int buf = 0;
                Fin.read((char*)&buf, sizeof(int));
                data.tuples[i].push_back(std::to_string(buf));

            } else if (data.info->fieldTypes[j] == "char(256)") {
                char * buf = new char[256];        
                Fin.read(buf, 256);
                std::string bufString = buf;                       
                delete[]buf;
                data.tuples[i].push_back(bufString);

            } else {
                bool buf = true;
                Fin.read((char *)&buf, sizeof(bool));
                data.tuples[i].push_back(std::to_string(buf));
            }
        }
    }

    Fin.close();
    return 0;
}


int binaryTxt(std::string fileName) {

    struct data data;
    parseBinary(fileName, data);
    fileName.erase(fileName.length() - 4);
    std::ofstream fOut;         
    fOut.open(fileName + ".txt");   

    int n = data.info->n;
    int m = data.info->m;

    fOut << n << " " << m << std::endl;

    std::string str = "";
    for (int i = 0; i < m; i++) {
        str = convertStr(data.info->fieldNames[i]);
        fOut << str << " ";
    }
    fOut << std::endl;

    std::vector<std::string> fieldTypes = {};
    for (int i = 0; i < m; i++) {
        str = data.info->fieldTypes[i];
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