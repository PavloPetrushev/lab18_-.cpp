// lab18_Петуршев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

class Matrix {
private:
    int data[5][5];

public:
    Matrix() {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                data[i][j] = 0;
            }
        }
    }

    Matrix(int init[5][5]) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                data[i][j] = init[i][j];
            }
        }
    }

    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int init1[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int init2[5][5] = {
        {5, 4, 3, 2, 1},
        {10, 9, 8, 7, 6},
        {15, 14, 13, 12, 11},
        {20, 19, 18, 17, 16},
        {25, 24, 23, 22, 21}
    };

    Matrix mat1(init1);
    Matrix mat2(init2);

    std::cout << "Матриця 1:" << std::endl;
    mat1.print();
    std::cout << std::endl;

    std::cout << "Матриця 2:" << std::endl;
    mat2.print();
    std::cout << std::endl;

    Matrix sum = mat1 + mat2;
    std::cout << "Сума матриць:" << std::endl;
    sum.print();
    std::cout << std::endl;

    Matrix diff = mat1 - mat2;
    std::cout << "Різниця матриць:" << std::endl;
    diff.print();
    std::cout << std::endl;

    bool areEqual = (mat1 == mat2);
    std::cout << "Матриця 1 " << (areEqual ? "дорівнює" : "не дорівнює") << " матриці 2" << std::endl;

    return 0;
}
