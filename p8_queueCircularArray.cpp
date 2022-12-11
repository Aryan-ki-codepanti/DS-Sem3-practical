#include <iostream>
#define GARBAGE -6969;
using namespace std;

class CircularQueue
{

    // front has idx of 1st element and back has idx of last element of queue
    int front = -1, back = -1, size;
    int *arr;

public:
    CircularQueue(int a)
    {
        size = a;
        arr = new int[a];
    }

    bool isEmpty()
    {
        return front == -1 && back == -1;
    }

    bool isFull()
    {
        int x = (back + 1) % size;
        return x == front;
    }

    void enqueue(int n)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty())
        {
            // 1st time 1st element
            front = 0;
            back = 0;
            arr[back] = n;
            return;
        }

        // other case
        back = (back + 1) % size;
        arr[back] = n;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Overflow" << endl;
            return GARBAGE;
        }

        int x = arr[front];
        if (front == back) // last element to be removed
        {
            front = -1;
            back = -1;
        }
        else // other case
            front = (front + 1) % size;
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty queue" << endl;
            return;
        }

        if (front <= back)
        {
            cout << "Front -> ";
            for (int i = front; i <= back; i++)
                cout << arr[i] << " ";
            cout << "<- Back" << endl;
            return;
        }
        // front > back
        cout << "Front -> ";
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= back; i++)
            cout << arr[i] << " ";
        cout << "<- Back" << endl;
    }
};

int main()
{
    int n, x, choice;
    cout << "Enter max capacity of queue : ";
    cin >> n;
    CircularQueue queue(n);

    while (true)
    {
        cout << "-----Queue Menu-------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Make a choice : ";
        cin >> choice;

        if (choice == 4)
        {
            cout << "Exiting program" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter element to be enqueued : ";
            cin >> x;
            queue.enqueue(x);
            break;
        case 2:
            x = queue.dequeue();
            cout << "Dequeued : " << x << endl;
            break;
        case 3:
            queue.display();
            break;

        default:
            cout << "Make a valid choice" << endl;
            break;
        }
    }

    return 0;
}