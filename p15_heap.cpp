#include <iostream>
using namespace std;
#define GARBAGE -6969;
// Priority queue with binary max heap

class BinaryMaxHeap
{
    int max_size, size;
    int *arr;

public:
    BinaryMaxHeap(int n)
    {
        max_size = n;
        size = 0;
        arr = new int[n];
    }

    bool isFull()
    {
        return size == max_size - 1;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    int getMax()
    {
        if (isEmpty())
            return GARBAGE;
        return arr[0];
    }

    // down
    void max_heapify(int i)
    {
        int L = left(i);
        int R = right(i);
        int largest = i;

        if (L < size && arr[L] > arr[largest])
            largest = L;

        if (R < size && arr[R] > arr[largest])
            largest = R;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            max_heapify(largest);
        }
    }

    int extract_max()
    {
        if (isEmpty())
            return GARBAGE;
        int max = arr[0];       // save max
        arr[0] = arr[size - 1]; // copy last to root
        size--;
        max_heapify(0); // heapify
        return max;
    }

    // update(increase) ith to x , up
    void increase_key(int i, int x)
    {
        if (i >= size || x < arr[i])
        {
            cout << "Invalid operation" << endl;
            return;
        }
        arr[i] = x;
        while (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // update(increase) ith to x ,down
    void decrease_key(int i, int x)
    {
        if (i >= size || x > arr[i])
        {
            cout << "Invalid operation" << endl;
            return;
        }
        arr[i] = x;
        max_heapify(i);
    }

    // inserts a to heap
    void insert_element(int a)
    {
        if (isFull())
        {
            cout << "HEAP OVERFLOW" << endl;
            return;
        }

        arr[size++] = a;
        int i = size - 1;
        while (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // delete element at ith
    void delete_idx(int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Invalid operation" << endl;
            return;
        }
        arr[i] = arr[size - 1];
        size--;
        max_heapify(i);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Heap" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    BinaryMaxHeap h(8);
    h.insert_element(4);
    h.insert_element(0);
    h.insert_element(1);
    h.insert_element(10);
    h.insert_element(5);
    h.display();
    cout << "Max : " << h.extract_max() << endl;
    h.display();
    return 0;
}