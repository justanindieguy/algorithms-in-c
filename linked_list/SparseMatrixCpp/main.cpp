#include <iostream>
#include "Sparse.h"

int main() {
    Sparse sparseOne(4, 4, 6);
    Sparse sparseTwo(4, 4, 4);
    Sparse sparseSum;

    std::cout << "Matrix One insert." << std::endl;
    sparseOne.insert();

    std::cout << std::endl << "Matrix Two insert." << std::endl;
    sparseTwo.insert();

    std::cout << std::endl << "Matrix One:" << std::endl;
    sparseOne.display();

    std::cout << std::endl << "Matrix Two:" << std::endl;
    sparseTwo.display();

    sparseSum = sparseOne.add(sparseTwo);
    std::cout << std::endl << "Sum Matrix:" << std::endl;
    sparseSum.display();

    return 0;
}
