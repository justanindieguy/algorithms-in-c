#include <iostream>

class LowerTriangular {
private:
    int* array;
    int n;

public:
    LowerTriangular() {
        n = 2;
        array = new int[2 * (2 + 1) / 2];
    }

    LowerTriangular(int n) {
        this->n = n;
        array = new int[n * (n + 1) / 2];
    }

    ~LowerTriangular() {
        delete []array;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getDimension();
};

void LowerTriangular::set(int i, int j, int x) {
    if (i >= j) {
        array[i * (i - 1) / 2 + j - 1] = x;
    }
}

int LowerTriangular::get(int i, int j) {
    if (i >= j) {
        return array[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void LowerTriangular::display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                std::cout << array[i * (i - 1) / 2 + j - 1] << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

int LowerTriangular::getDimension() {
    return n;
}

int main() {
    int d, x;
    std::cout << "Enter dimensions: ";
    std::cin >> d;

    LowerTriangular matrix(d);

    std::cout << "Enter all elements: " << std::endl;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            std::cin >> x;
            matrix.set(i, j, x);
        }
    }

    std::cout << std::endl;
    matrix.display();

    return 0;
}
