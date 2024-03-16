#include <iostream>
using namespace std;


class Matrix
{
private:
    int* data;
    int cols;
    int rows;

public:
    Matrix(int rows, int cols) : rows{ rows }, cols{ cols }
    {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
    }

    //Копіювання
    Matrix(const Matrix& other) : rows{ other.cols }, cols{ other.cols }
    {
        data = new int[rows, cols];
        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~Matrix() {
        delete[]data;
    }


    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++)
        {
            result.data[i] = data[i] + other.data[i];
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.data[i * result.cols + j] += data[i * cols + k] * other.data[k * other.cols + j];
                }
            }
        }
    }

    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i * matrix.cols + j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main()
{
    Matrix A(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    Matrix B(2, 2);
    B(0, 0) = 5;
    B(0, 1) = 6;
    B(1, 0) = 7;
    B(1, 1) = 8;

    Matrix C = A + B;
    std::cout << "A + B:\n" << C << std::endl;

    Matrix D = A - B;
    std::cout << "A - B:\n" << D << std::endl;

    Matrix E = A * B;
    std::cout << "A * B:\n" << E << std::endl;

    return 0;
}