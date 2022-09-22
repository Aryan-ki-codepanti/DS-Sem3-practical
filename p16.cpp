#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    int top = -1, size;
    T *arr;

public:
    Stack(int a)
    {
        size = a;
        arr = new T[a];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(T element)
    {
        arr[++top] = element;
    }

    T pop()
    {
        return arr[top--];
    }

    T peek()
    {
        return arr[top];
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool checkPrecedence(char a, char b)
{
    if (a == '*' && isOperator(b))
        return true;
    else if (a == '/' && isOperator(b))
        return true;
    else if (a == '+' && (b == '+' || b == '-'))
        return true;
    else if (a == '-' && (b == '+' || b == '-'))
        return true;
    return false;
}

string infixToPostfix(string infix)
{
    int n = infix.length();
    Stack<char> operator_stack(n);
    string postfix = "";

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(infix[i]))
            postfix += infix[i];
        else
        {
            while (!operator_stack.isEmpty() && checkPrecedence(operator_stack.peek(), infix[i]))
                postfix += operator_stack.pop();
            operator_stack.push(infix[i]);
        }
    }
    while (!operator_stack.isEmpty())
        postfix += operator_stack.pop();

    return postfix;
}

int eval(int first, int second, char op)
{
    switch (op)
    {
    case '/':
        return first / second;
    case '*':
        return first * second;
    case '+':
        return first + second;
    case '-':
        return first - second;
    default:
        return 0;
    }
}

int evaluatePostfix(string postfix)
{

    int n = postfix.length();
    Stack<int> operand_stack(n);

    int first, second;
    for (int i = 0; i < n; i++)
    {
        // operand
        if (!isOperator(postfix[i]))
            operand_stack.push(postfix[i] - '0'); // convert to ints

        else
        {
            second = operand_stack.pop();
            first = operand_stack.pop();
            operand_stack.push(eval(first, second, postfix[i])); // push the result of first op second
        }
    }

    return operand_stack.pop();
}

int main()
{
    string infix, postfix;
    cout << "Enter infix : " << endl;
    cin >> infix;

    postfix =  infixToPostfix(infix);
    cout << "Postfix : " << postfix << endl;
    cout << "Value: " << evaluatePostfix(postfix) << endl;
    return 0;
}