#include "reg_operations.hpp"

int main() {
    regOperations oper;
    oper.regUnion("test_data/a1.bin", "test_data/a2.bin", "test_data/aRes.bin");

    binaryTxt("test_data/a.bin");
    binaryTxt("test_data/a2.bin");
    binaryTxt("test_data/aRes.bin");

    oper.setQuantityTreads(3);
    oper.regIntersection("test_data/aRes.bin", "test_data/a1.bin", "test_data/aRes2.bin");
    oper.regIntersection("test_data/aRes.bin", "test_data/a2.bin", "test_data/aRes3.bin");
    binaryTxt("test_data/aRes2.bin");
    binaryTxt("test_data/aRes3.bin");

    oper.regDifference("test_data/aRes.bin", "test_data/a1.bin", "test_data/aRes4.bin");
    oper.regDifference("test_data/aRes.bin", "test_data/a2.bin", "test_data/aRes5.bin");
    binaryTxt("test_data/aRes4.bin");
    binaryTxt("test_data/aRes5.bin");

    oper.regCartesian("test_data/a1.bin", "test_data/a2.bin", "test_data/aRes6.bin");
    binaryTxt("test_data/aRes6.bin");

    binaryTxt("test_data/b1.bin");
    oper.regProjection("test_data/b1.bin", "test_data/proj.txt", "test_data/aRes7.bin");
    binaryTxt("test_data/aRes7.bin");

    //binaryTxt("books_authors.bin");
    return 0;
}