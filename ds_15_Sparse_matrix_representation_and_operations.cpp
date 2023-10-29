#include <iostream>
#include <vector>
using namespace std;

class SparseMatrix {
private:
    int rows, cols;
    vector<vector<int>> matrix;

public:
    SparseMatrix(int m, int n) : rows(m), cols(n) {
        matrix.resize(m, vector<int>(n, 0));
    }

    void setValue(int i, int j, int val) {
        matrix[i][j] = val;
    }

    int getValue(int i, int j) {
        return matrix[i][j];
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    SparseMatrix add(SparseMatrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices must have the same dimensions for addition." << endl;
            return *this;
        }

        SparseMatrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setValue(i, j, matrix[i][j] + other.getValue(i, j));
            }
        }

        return result;
    }

    SparseMatrix multiply(SparseMatrix& other) {
        if (cols != other.rows) {
            cout << "Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication." << endl;
            return *this;
        }

        SparseMatrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.setValue(i, j, result.getValue(i, j) + matrix[i][k] * other.getValue(k, j));
                }
            }
        }

        return result;
    }
};

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    SparseMatrix A(2, 3);
    A.setValue(0, 0, 1);
    A.setValue(0, 2, 2);
    A.setValue(1, 1, 3);

    SparseMatrix B(3, 2);
    B.setValue(0, 0, 4);
    B.setValue(1, 1, 5);

    cout << "Matrix A:" << endl;
    A.display();
    cout << endl;

    cout << "Matrix B:" << endl;
    B.display();
    cout << endl;

    SparseMatrix C = A.add(B);
    cout << "Addition of A and B:" << endl;
    C.display();
    cout << endl;

    SparseMatrix D = A.multiply(B);
    cout << "Multiplication of A and B:" << endl;
    D.display();
    cout << endl;

    return 0;
}