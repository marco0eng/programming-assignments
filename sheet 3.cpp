#include <iostream>
#include <algorithm>
#include <math.h>
#include <string> 
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#define ll long long
#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

using namespace std;

// Function to fill a matrix with user-provided elements
vector<vector<double>> fillMatrix(int rows, int columns) {
    vector<vector<double>> matrix(rows, vector<double>(columns, 0.0));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Function to print a matrix
void printMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to perform matrix addition
vector<vector<double>> addMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int columns2 = matrix2[0].size();

    if (rows1 != rows2 || columns1 != columns2) {
        cerr << "Matrix dimensions mismatch for addition!" << endl;
        return {};
    }

    vector<vector<double>> result(rows1, vector<double>(columns1, 0.0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to perform matrix subtraction
vector<vector<double>> subtractMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int columns2 = matrix2[0].size();

    if (rows1 != rows2 || columns1 != columns2) {
        cerr << "Matrix dimensions mismatch for subtraction!" << endl;
        return {};
    }

    vector<vector<double>> result(rows1, vector<double>(columns1, 0.0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to perform matrix multiplication
vector<vector<double>> multiplyMatrices(const vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) {
    int rows1 = matrix1.size();
    int columns1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int columns2 = matrix2[0].size();

    if (columns1 != rows2) {
        cerr << "Matrix dimensions mismatch for multiplication!" << endl;
        return {};
    }

    vector<vector<double>> result(rows1, vector<double>(columns2, 0.0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
vector<vector<double>> transposeMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<vector<double>> result(columns, vector<double>(rows, 0.0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
    // Getting user input for matrix dimensions
    int rows1, columns1, rows2, columns2;

    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> columns1;

    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> columns2;

    // Filling the matrices
  vector<vector<double>> matrix1 = fillMatrix(rows1, columns1);
    vector<vector<double>> matrix2 = fillMatrix(rows2, columns2);

    // Operating on the matrices
    cout << "Select an operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Transpose" << endl;

    int operation;
    cout << "Enter the operation number: ";
    cin >> operation;

    switch (operation) {
    case 1: {
        vector<vector<double>> result = addMatrices(matrix1, matrix2);
        if (!result.empty()) {
            cout << "Result:" << endl;
            printMatrix(result);
        }
        break;
    }
    case 2: {
        vector<vector<double>> result = subtractMatrices(matrix1, matrix2);
        if (!result.empty()) {
            cout << "Result:" << endl;
            printMatrix(result);
        }
        break;
    }
    case 3: {
        vector<vector<double>> result = multiplyMatrices(matrix1, matrix2);
        if (!result.empty()) {
            cout << "Result:" << endl;
            printMatrix(result);
        }
        break;
    }
    case 4: {
        int transposeChoice;
        cout << "Select the matrix to transpose:" << endl;
        cout << "1. Matrix 1" << endl;
        cout << "2. Matrix 2" << endl;
        cout << "Enter the matrix number: ";
        cin >> transposeChoice;

        vector<vector<double>> result;
        if (transposeChoice == 1) {
            result = transposeMatrix(matrix1);
        }
        else if (transposeChoice == 2) {
            result = transposeMatrix(matrix2);
        }
        else {
            cout << "Invalid matrix number!" << endl;
        }

        if (!result.empty()) {
            cout << "Result:" << endl;
            printMatrix(result);
        }
        break;
    }
    default:
        cout << "Invalid operation number!" << endl;
    }

    return 0;
}
