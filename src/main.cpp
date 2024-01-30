#include "reg_operations.hpp"

int main() {
    regOperations oper;
    oper.regUnion("authors1.bin", "authors2.bin", "authorsResult.bin");

    binaryTxt("authors1.bin");
    binaryTxt("authors2.bin");
    binaryTxt("authorsResult.bin");

    oper.setQuantityTreads(3);
    oper.regIntersection("authorsResult.bin", "authors1.bin", "authorsResult2.bin");
    oper.regIntersection("authorsResult.bin", "authors2.bin", "authorsResult3.bin");
    binaryTxt("authorsResult2.bin");
    binaryTxt("authorsResult3.bin");

    //binaryTxt("books.bin");
    //binaryTxt("books_authors.bin");
    return 0;
}