#include <iostream>

class Element {

public:
    int i;
    int j;
    int x;
};

class Sparse {

private:
    int m;
    int n;
    int num;
    Element *ele;

public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    ~Sparse() {
        delete [] ele;
    }

    Sparse operator+ (Sparse &secondMatrix);
    friend std::istream & operator >> (std::istream &is, Sparse &s);
    friend std::ostream & operator << (std::ostream &os, Sparse &s);
};

Sparse Sparse::operator+ (Sparse &secondMatrix) {

    int i, j, k;

    /*
    if (m != secondMatrix.m || n != secondMatrix.n) {
        return NULL;
    }
    */
    

    Sparse *sum = new Sparse(m, n, num + secondMatrix.num);
    i = j = k = 0;

    while (i < num && j < secondMatrix.num) {

        if (ele[i].i < secondMatrix.ele[j].i) {

            sum->ele[k++] = ele[j++];

        } else if (ele[i].i > secondMatrix.ele[j].i) {

            sum->ele[k++] = secondMatrix.ele[j++];

        } else {

            if (ele[i].j < secondMatrix.ele[j].j) {

                sum->ele[k++] = ele[i++];

            } else if (ele[i].j > secondMatrix.ele[j].j) {

                sum->ele[k++] = secondMatrix.ele[j++];

            } else {

                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + secondMatrix.ele[j++].x;

            }

        }
    }

    for (; i < num; i++) {
        sum->ele[k++] = ele[i];
    }

    for (; j < secondMatrix.num; j++) {
        sum->ele[k++] = secondMatrix.ele[j++];
    }

    sum->num = k;

    return *sum;
}

std::istream & operator >> (std::istream &is, Sparse &s) {
    
    std::cout << "Enter non-zero elements:" << std::endl;
    for (int i = 0; i < s.num; i++) {
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    std::cout << std::endl;
    return is;
}

std::ostream & operator << (std::ostream &os, Sparse &s) {
    
    int k = 0;

    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (s.ele[k].i == i && s.ele[k].j == j) {
                std::cout << s.ele[k++].x << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return os;
}

int main() {

    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);

    std::cout << "Enter first matrix." << std::endl;
    std::cin >> s1;

    std::cout << "Enter second matrix." << std::endl;
    std::cin >> s2;

    Sparse sum = s1 + s2;

    std::cout << "First Matrix:" << std::endl << s1;
    std::cout << "Second Matrix:" << std::endl << s2;
    std::cout << "Sum Matrix:" << std::endl << sum;

    return 0;
}
