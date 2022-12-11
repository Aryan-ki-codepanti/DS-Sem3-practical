
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

class DoubleEndedQueue
{
    Node *front, *back;

public:
    DoubleEndedQueue()
    {
        front = back = NULL;
    }

    bool isEmpty()
    {
        return front == NULL && back == NULL;
    }

    void enqueueBack(int a)
    {
        Node *newNode = new Node(a);

        // case 1 : first insertion
        if (isEmpty())
        {
            front = back = newNode;
            return;
        }

        // case 2 : other
        back->next = newNode;
        back = newNode;
    }

    void enqueueFront(int a)
    {
        Node *newNode = new Node(a);

        // Case 1 : Empty list
        if (isEmpty())
        {
            front = back = newNode;
            return;
        }

        // Case 2 : 1 or more nodes present already

        newNode->next = front;
        front = newNode;
    }

    int dequeueFront()
    {
        // Case 1 : Empty Linked List
        if (isEmpty())
        {
            cout << "Can't delete front from empty list" << endl;
            return GARBAGE;
        }

        Node *delNode;
        int x = front->data;

        // Case 2 : one node in  linked list
        delNode = front;
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

    int dequeueBack()
    {
        // Case 1 : Empty Linked List
        if (isEmpty())
        {
            cout << "Can't delete back from empty list" << endl;
            return GARBAGE;
        }

        Node *delNode;
        int x = back->data;

        // Case 2 : one node in  linked list
        delNode = back;
        if (front == back)
        {
            front = back = NULL;
            delete delNode;
            return x;
        }

        // Case 3 : Other
        Node *current = front;
        while (current->next != back)
            current = current->next;

        current->next = NULL;
        back = current;
        delete delNode;
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node *ptr = front;
        cout << "FRONT -> ";
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "BACK" << endl;
    }
};

int main()
{
    DoubleEndedQueue deq;
    deq.enqueueFront(3);
    deq.enqueueFront(5);
    deq.enqueueFront(9);
    deq.enqueueBack(7);
    deq.enqueueBack(8);
    deq.display();
    cout << "Deqeueued : " << deq.dequeueFront() << endl;
    deq.display();
    cout << "Deqeueued : " << deq.dequeueBack() << endl;
    deq.display();
    return 0;
}