#include <iostream>
#include <climits>

using namespace std;

// Расстановка скобок в выражении
void printBrackets(int i, int j, int n, int *bracket, char &name) {
    // Случай, когда осталась одна матрица в цепочке
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";

    // Рекурсивная расстановка скобок от i до bracket[j][i].
    printBrackets(i, *((bracket + j * n) + i), n, bracket, name);
    cout<<'*';
    // Рекурсивная расстановка скобок от bracket[j][i] + 1 до i.
    printBrackets(*((bracket + j * n) + i) + 1, j, n, bracket, name);

    cout << ")";
}

// Матрица Ai размерностью arr[i-1] x arr[i] для i = 1..size
void matrixChain(int *arr, int size) {
//    min[i,j] = Минимальное количество скалярных умножений
//    max[i,j] = Максимальное количество скалярных умножений

    int min[size][size];
    int max[size][size];

    // Значение равно нулю для одной матрицы
    for (int i = 1; i < size; i++) {
        min[i][i] = 0;
        max[i][i] = 0;
    }

    // len - длина цепи матриц
    for (int len = 2; len < size; len++) {

        for (int i = 1; i < size - len + 1; i++) {

            int j = i + len - 1;
            min[i][j] = INT_MAX;
            max[i][j] = INT_MIN;

            for (int n = i; n <= j - 1; n++) {
                int mul = min[i][n] + min[n + 1][j] + arr[i - 1] * arr[n] * arr[j];
                if (mul < min[i][j]){
                    min[i][j] = mul;
                    min[j][i] = n;
                }
                if (mul >= max[i][j]) {
                    max[i][j] = mul;
                    max[j][i] = n;
                }
            }
        }
    }

    char mName = 'A';
    cout << "Расстановка скобок для минимального количества умножений: ";
    printBrackets(1, size - 1, size, (int *) min, mName);
    cout << "\nМинимальное количество скалярных умножений: " << min[1][size - 1] << endl;

    mName = 'A';
    cout << "Расстановка скобок для максимального количества умножений: ";
    printBrackets(1, size - 1, size, (int *) max, mName);
    cout << "\nМаксимальное количество скалярных умножений: " << max[1][size - 1];
}


int main() {
    setlocale(LC_ALL, "Russian");
    //Массив размеров матриц по условию
    int arr[] = {5, 10, 3, 12, 5, 50, 6};
    //int arr[] = { 10, 100, 5, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    matrixChain(arr, size);
    return 0;
}