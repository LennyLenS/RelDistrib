#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class regOperations {
    private:
        int quantityTreads;

    public:
        regOperations();

        int regUnion(std::string fileName1, std::string fileName2, std::string fileNameResult);
        /*int regIntersection(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regDifference(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regCartesian(std::string fileName1, std::string fileName2, std::string fileNameResult);
        int regProjection(std::string fileName, std::string fileNameResult);
        int regLimitation(std::string fileName, std::string fileNameResult);
        int regConnection(std::string fileName1, std::string fileName2, std::string fileNameResult);*/
};