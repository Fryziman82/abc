#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для знаходження мінімального елемента в секторі над головною діагоналлю
int findMinAboveDiagonal(vector<vector<int>>& matrix) {
    int minVal = INT_MAX;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i + 1; j < matrix[i].size(); j++) {
            minVal = min(minVal, matrix[i][j]);
        }
    }
    return minVal;
}

// Функція для знаходження мінімального елемента в секторі під головною діагоналлю
int findMinBelowDiagonal(vector<vector<int>>& matrix) {
    int minVal = INT_MAX;
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < i; j++) {
            minVal = min(minVal, matrix[i][j]);
        }
    }
    return minVal;
}

// Функція для заміни елементів головної діагоналі
void replaceDiagonalElements(vector<vector<int>>& matrix, int newVal) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][i] = newVal;
    }
}

int main() {
    // Введення вхідних даних
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    // Виклик функцій
    int minAbove = findMinAboveDiagonal(matrix);
    int minBelow = findMinBelowDiagonal(matrix);
    int maxMin = max(minAbove, minBelow);

    replaceDiagonalElements(matrix, maxMin);

    // Виведення результатів
    for (auto row : matrix) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
