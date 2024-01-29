#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "binary_parser.h"

bool fieldEquality(struct data& data1, struct data& data2);
std::string formatStr(std::string str);
int recordingFileInfo(struct data& data, int quantityTuples, FILE *f);
int recordingData(struct data& data, FILE *f);

class regOperations {
    private:
        int quantityTreads;

    public:
        regOperations();

        int getQuantityTreads();
        int setQuantityTreads(int value);

        int regUnion(std::string fileName1, std::string fileName2, std::string fileNameResult);
        /*int regIntersection(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regDifference(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regCartesian(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regProjection(std::string fileName, std::string fileNameResult);
        int regLimitation(std::string fileName, std::string fileNameResult);
        int regConnection(std::string fileName1, std::string fileName2, std::string fileNameResult);*/
};



bool fieldEquality(struct data& data1, struct data& data2) {
    int m = data1.info->m;
    if (m != data2.info->m) {
        return false;
    }

    for (int i = 0; i < m; i++) {
        if (!((data1.info->fieldNames[i] == data2.info->fieldNames[i]) && (data1.info->fieldTypes[i] == data1.info->fieldTypes[i]))) {
            return false;
        }
    }
    return true;
}

std::string formatStr(std::string str) {
    return str + std::string(255 - str.size(), ' ');
}

int recordingFileInfo(struct data& data, int quantityTuples, FILE *f) {
    int m = data.info->m;
    fwrite(&quantityTuples, sizeof(int), 1, f);
    fwrite(&m, sizeof(int), 1, f);

    for (int i = 0; i < m; i++) {
        std::string nameField = data.info->fieldNames[i];
        fwrite((char*) nameField.c_str(), nameField.length() + 1, 1, f);
    }

    for (int i = 0; i < m; i++) {
        std::string nameType = formatStr(data.info->fieldTypes[i]);
        fwrite((char*) nameType.c_str(), nameType.length() + 1, 1, f);
    }

    return 0;
}

int recordingData(struct data& data, FILE *f) {
    int n = data.info->n;
    int m = data.info->m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::string value = data.tuples[i][j];
        
            if (data.info->fieldTypes[j] == "int") {
                int buf = stoi(value);
                fwrite(&buf, sizeof(int), 1, f);

            } else {
                fwrite((char*) value.c_str(), value.length() + 1, 1, f);
            }
        }
    }

    return 0;
}



regOperations::regOperations() {
    this->quantityTreads = 1;
}

int regOperations::getQuantityTreads() {
    return this->quantityTreads;
}

int regOperations::setQuantityTreads(int value) {
    this->quantityTreads = value;
    return 0;
}

int regOperations::regUnion(std::string fileName1, std::string fileName2, std::string fileNameResult) {
    struct data data1;
    getFileInfo(fileName1, data1);
    struct data data2;
    getFileInfo(fileName2, data2);

    if (!fieldEquality(data1, data2)) {
        return 1;
    }

    int n = data1.info->n + data2.info->n;
    int quantityTreads = this->getQuantityTreads();
    if (quantityTreads == 1 || n < 100000) {
        parseBinary(fileName1, data1);
        parseBinary(fileName2, data2);

        FILE *f; 
        f = fopen(fileNameResult.c_str(), "wb");
        recordingFileInfo(data1, n, f);
        recordingData(data1, f);

        int indexId = -1;
        int m = data2.info->m;
        std::string strId = formatStr("id");
        for (int i = 0; i < m; i++) {
            if (strId == data2.info->fieldNames[i]) {
                indexId = i;
                break;
            }
        }

        if (indexId != -1) {
            int n1 = data1.info->n;
            int n2 = data2.info->n;
            for (int i = 0; i < n2; i++) {
                int value = n1 + i + 1;
                data2.tuples[i][indexId] = std::to_string(value);
            }
        }
        recordingData(data2, f);
        fclose(f);
    }

    return 0;
}