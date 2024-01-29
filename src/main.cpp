#include "reg_operations.hpp"

int main() {
    regOperations oper;
    oper.regUnion("authors1.bin", "authors2.bin", "authorsResult.bin");

    binaryTxt("authors1.bin");
    binaryTxt("authors2.bin");
    binaryTxt("authorsResult.bin");
    //binaryTxt("books.bin");
    //binaryTxt("books_authors.bin");
    return 0;
}