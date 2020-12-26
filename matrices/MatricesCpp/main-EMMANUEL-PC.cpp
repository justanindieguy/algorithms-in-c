#include <iostream>

class Matrix {
private:
    int **array;
    int n;

public:
    Matrix() {
        n = 2;
        array = new int*[2];

        for (int i = 0; i < n; i++) {
            array[i] = new int[n];
        }
    }

    Matrix(int n) {
        this->n = n;
        array = new int*[n];

        for (int i = 0; i < n; i++) {
            array[i] = new int[n];
        }
    }

    ~Matrix() {
        delete[]array;
    }

    void create();
    void display();
    void function();
};

void Matrix::create() {
    int x;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> x;
            array[i - 1][j - 1] = x;
        }
    }
}

void Matrix::display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << array[i - 1][j - 1] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::function() {
    int c = 100;
    int temp;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp = array[i - 1][j - 1] + 100;
            array[i - 1][j - 1] = array[j - 1][i - 1];
            array[j - 1][i - 1] = temp - c;
        }
    }

    display();
}

int main() {
    int n;
    std::cout << "Enter dimension: ";
    std::cin >> n;
    
    Matrix matrix(n);

    std::cout << "Enter elements:" << std::endl;
    matrix.create();

    std::cout << std::endl;
    std::cout << "The matrix is: " << std::endl;
    matrix.display();

    std::cout << std::endl;
    std::cout << "The new matrix is: " << std::endl;
    matrix.function();

    return 0;
}
