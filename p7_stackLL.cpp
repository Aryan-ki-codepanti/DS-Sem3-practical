
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

    int pop()
    {
        // Case 1 : Empty stack
        if (isEmpty())
        {
            cout << "Can't delete top from empty stack" << endl;
            return GARBAGE;
        }

        // Case 2 : general
        Node *delNode;
        delNode = top;
        int x = top->data;
        top = top->next;
        delete delNode;
        return x;
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
    cout << s.pop() << endl;
    s.display();
    return 0;
}