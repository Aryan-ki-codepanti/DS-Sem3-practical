#include <iostream>
using namespace std;
#define GARBAGE -6969

class DiagnolMatrix
{
    int size, n;
    int *arr;

public:
    DiagnolMatrix(int n)
    {
        size = n;
        this->n = n;
        arr = new int[size];
    }

    void set(int i, int j, int x)
    {
        // boundary check
        if (i < 1 || j < 1 || i > n || j > n)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        if (i != j)
            return;
        // calc k
        int k = i - 1;
        arr[k] = x;
    }

    int get(int i, int j)
    {
        // boundary check
        if (i < 1 || j < 1 || i > size || j > size)
        {
            cout << "Out of Bounds" << endl;
            return GARBAGE;
        }

        if (i != j)
            return 0;
        // calc k
        int k = i - 1;
        return arr[k];
    }
};

class LowerTriangularMatrix
{
    int size, n;
    int *arr;

public:
    LowerTriangularMatrix(int n)
    {
        size = n * (n + 1) / 2;
        this->n = n;
        arr = new int[size];
    }

    void set(int i, int j, int x)
    {
        // boundary check
        if (i < 1 || j < 1 || i > n || j > n)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        if (i < j)
            return;
        // calc k
        int k = i * (i - 1) / 2 + (j - 1);
        arr[k] = x;
    }

    int get(int i, int j)
    {
        // boundary check
        if (i < 1 || j < 1 || i > size || j > size)
        {
            cout << "Out of Bounds" << endl;
            return GARBAGE;
        }

        if (i < j)
            return 0;
        // calc k
        int k = i * (i - 1) / 2 + (j - 1);
        return arr[k];
    }
};

class UpperTriangularMatrix
{
    int size, n;
    int *arr;

public:
    UpperTriangularMatrix(int n)
    {
        size = n * (n + 1) / 2;
        this->n = n;
        arr = new int[size];
    }

    void set(int i, int j, int x)
    {
        // boundary check
        if (i < 1 || j < 1 || i > n || j > n)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        if (i > j)
            return;
        // calc k
        int k = j * (j - 1) / 2 + (i - 1);
        arr[k] = x;
    }

    int get(int i, int j)
    {
        // boundary check
        if (i < 1 || j < 1 || i > size || j > size)
        {
            cout << "Out of Bounds" << endl;
            return GARBAGE;
        }

        if (i > j)
            return 0;
        // calc k
        int k = j * (j - 1) / 2 + (i - 1);
        return arr[k];
    }
};

class SymmetricMatrix
{
    int size, n;
    int *arr;

public:
    SymmetricMatrix(int n)
    {
        size = n * (n + 1) / 2;
        this->n = n;
        arr = new int[size];
    }

    void set(int i, int j, int x)
    {
        // boundary check
        if (i < 1 || j < 1 || i > n || j > n)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        if (i < j)
            swap(i, j);
        // calc k
        int k = i * (i - 1) / 2 + (j - 1);
        arr[k] = x;
    }

    int get(int i, int j)
    {
        // boundary check
        if (i < 1 || j < 1 || i > size || j > size)
        {
            cout << "Out of Bounds" << endl;
            return GARBAGE;
        }

        if (i < j)
            swap(i, j);
        // calc k
        int k = i * (i - 1) / 2 + (j - 1);
        return arr[k];
    }
};

int main()
{
    // UpperTriangularMatrix d(4);
    SymmetricMatrix d(4);
    int n = 4, c = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d.set(i + 1, j + 1, ++c);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << d.get(i + 1, j + 1) << " ";
        cout << endl;
    }

    return 0;
}