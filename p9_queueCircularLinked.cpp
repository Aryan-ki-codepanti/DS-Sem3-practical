
#include <iostream>
#define GARBAGE -6969
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

class CircularLinkedQueue
{
    Node *front, *back;

public:
    CircularLinkedQueue()
    {
        front = back = NULL;
    }

    bool isEmpty()
    {
        return front == NULL && back == NULL;
    }

    void enqueue(int a)
    {
        Node *newNode = new Node(a);

        // case 1 : first insertion
        if (front == NULL && back == NULL)
        {
            front = back = newNode;
            back->next = front;
            return;
        }

        // case 2 : other
        back->next = newNode;
        back = newNode;
        back->next = front;
    }

    int dequeue()
    {
        // Case 1 : Empty Linked List
        if (isEmpty())
        {
            cout << "Can't delete front from empty list" << endl;
            return GARBAGE;
        }

        Node *delNode;
        int x = front->data;
        delNode = front;

        // Case 2 : one node in  linked list
        if (front == back)
        {
            front = back = NULL;
            delete delNode;
            return x;
        }

        // Case 3 : Other
        front = front->next;
        delete delNode;
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return;
        }

        Node *ptr = front;
        cout << "FRONT -> ";
        while (ptr != back)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << back->data << " -> ";
        cout << "BACK" << endl;
    }
};

int main()
{

    CircularLinkedQueue q;
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(10);
    q.display();

    cout << "Dequeued : " << q.dequeue() << endl;
    q.display();
    cout << "Dequeued : " << q.dequeue() << endl;
    q.display();
    return 0;
}