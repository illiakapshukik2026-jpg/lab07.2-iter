// Lab_7_2_Iter.cpp
// Капшук Ілля Віталійович
// Лабораторна робота № 7.2. 
// Опрацювання багатовимірних масивів ітераційним способом.
// Варіант 6.

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int RowMax(int** a, const int rowNo, const int n);
int MinOfMax(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -15;
    const int High = 35;
    const int k = 6; // кількість рядків
    const int n = 5; // кількість стовпчиків

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    cout << "Initial Matrix:" << endl;
    Print(a, k, n);

    int result = MinOfMax(a, k, n);
    cout << "Min of max elements in rows = " << result << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int RowMax(int** a, const int rowNo, const int n)
{
    int max = a[rowNo][0];
    for (int j = 1; j < n; j++)
    {
        if (a[rowNo][j] > max)
            max = a[rowNo][j];
    }
    return max;
}

int MinOfMax(int** a, const int k, const int n)
{
    int minOfMax = RowMax(a, 0, n);
    for (int i = 1; i < k; i++)
    {
        int maxInRow = RowMax(a, i, n);
        if (maxInRow < minOfMax)
            minOfMax = maxInRow;
    }
    return minOfMax;
}

