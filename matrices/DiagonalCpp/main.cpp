#include <iostream>

class Diagonal {
private:
    int *array;
    int n;

public:
    Diagonal() {
        n = 2;
        array = new int[2];
    }

    Diagonal(int n) {
        this->n = n;
        array = new int[n];
    }

    ~Diagonal() {
        delete[]array;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void Diagonal::set(int i, int j, int x) {
    if (i == j) {
        array[i - 1] = x;
    }
}

int Diagonal::get(int i, int j) {
    if (i == j) {
        return array[i - 1];
    }
    return 0;
}

void Diagonal::display() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                std::cout << array[i] << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    Diagonal matrix(4);
    matrix.set(1, 1, 5);
    matrix.set(2, 2, 8);
    matrix.set(3, 3, 9);
    matrix.set(4, 4, 1);

    matrix.display();

    return 0;
}