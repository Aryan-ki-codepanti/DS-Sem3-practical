
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

class LinkedStack
{

    // top is top , no size bounds
    Node *top;

public:
    LinkedStack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int a)
    {
        Node *newNode = new Node(a);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        // Case 1 : Empty stack
        if (isEmpty())
        {
            cout << "Can't delete top from empty stack" << endl;
            return;
        }

        Node *delNode;
        // Case 2 : one node in  stack
        delNode = top;
        top = top->next;
        delete delNode;
    }

    int topEl()
    {
        if (isEmpty())
            return GARBAGE;
        return top->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }

        cout << top->data << " <- TOP" << endl;
        Node *ptr = top->next;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    LinkedStack s;
    s.push(1);
    s.push(5);
    s.push(7);
    s.display();
    s.pop();
    s.display();
    return 0;
}