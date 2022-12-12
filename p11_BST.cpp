#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;

    Node(int a)
    {
        data = a;
        left = right = NULL;
    }
};

class BinarySearchTree
{
    int height;

public:
    Node *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    bool search(int a)
    {
        Node *current = root;

        while (current != NULL)
        {
            if (current->data == a)
                return true;
            else if (current->data < a)
                current = current->right;
            else // (current->data < a)
                current = current->left;
        }

        return false;
    }

    void inorder_recursive(Node *current)
    {
        if (current == NULL)
            return;

        inorder_recursive(current->left);
        cout << current->data << " ";
        inorder_recursive(current->right);
    }

    void preorder_recursive(Node *current)
    {
        if (current == NULL)
            return;

        cout << current->data << " ";
        preorder_recursive(current->left);
        preorder_recursive(current->right);
    }

    void postorder_recursive(Node *current)
    {
        if (current == NULL)
            return;

        postorder_recursive(current->left);
        postorder_recursive(current->right);
        cout << current->data << " ";
    }

    void inorder()
    {
        inorder_recursive(root);
        cout << endl;
    }
    void preorder()
    {
        preorder_recursive(root);
        cout << endl;
    }
    void postorder()
    {
        postorder_recursive(root);
        cout << endl;
    }

    void level_order()
    {
        queue<Node *> my_queue;
        my_queue.push(root);

        Node *current;
        while (!my_queue.empty())
        {
            current = my_queue.front();
            my_queue.pop();
            cout << current->data << " ";

            if (current->left != NULL)
                my_queue.push(current->left);
            if (current->right != NULL)
                my_queue.push(current->right);
        }
        cout << endl;
    }

    void insert_element(int a)
    {
        Node *newNode = new Node(a);
        // Case 1: insert into empty tree
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        // parent will be parent of current
        Node *parent, *current = root;
        while (current != NULL)
        {
            parent = current;
            if (current->data < a)
                current = current->right;
            else if (current->data > a)
                current = current->left;
            else
            {
                cout << "Duplicate not allowed : " << a << endl;
                return;
            }
        }

        if (parent->data < a)
            parent->right = newNode;
        else
            parent->left = newNode;
    }

    void delete_element(int a)
    {
        // Case 1 : last  deletion (Only root)
        if (root->data == a && root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        Node *parent = NULL, *current = root;
        while (current != NULL && current->data != a)
        {
            parent = current;
            if (current->data < a)
                current = current->right;
            else // (current->data > a)
                current = current->left;
        }

        // Case 2 : a not in tree
        if (current == NULL)
        {
            cout << a << " not found in tree" << endl;
            return;
        }

        // Case 5 : two children : delete by copying takin inorder predecessor (biggest node in left subtree )
        if (current->left != NULL && current->right != NULL)
        {
            Node *largest_parent = current, *largest = current->left; // in left subtree
            while (largest->right != NULL)
            {
                largest_parent = largest;
                largest = largest->right;
            }
            // copying largest from left subtree to current node
            current->data = largest->data;

            // converting our problem to case 3 or 4
            parent = largest_parent;
            current = largest;
        }

        // Case 3 : leaf node
        if (current->left == NULL && current->right == NULL)
        {
            if (parent->left == current)
                parent->left = NULL;
            else // parent->right == current
                parent->right = NULL;
            delete current;
            return;
        }

        // Case 4 : One Child (has right child)
        if (current->left == NULL)
        {
            // delete root
            if (current == root)
                root = current->right;
            else if (parent->left == current)
                parent->left = current->right;
            else // parent->right == current or parent->data < a
                parent->right = current->right;
            delete current;
            return;
        }

        // Case 4 : One Child (contd : has left child)
        if (current->right == NULL)
        {
            // delete root
            if (current == root)
                root = current->left;
            else if (parent->left == current)
                parent->left = current->left;
            else // parent->right == current or parent->data < a
                parent->right = current->left;
            delete current;
            return;
        }
    }

    int get_height(Node *current)
    {
        if (current == NULL)
            return -1;

        int left_height = get_height(current->left);
        int right_height = get_height(current->right);
        return 1 + max(left_height, right_height);
    }

    void search_and_replace(int x, int y)
    {
        if (!search(x))
        {
            cout << x << " not found" << endl;
            return;
        }
        delete_element(x);
        insert_element(y);
    }
};

int main()
{
    BinarySearchTree b;
    b.insert_element(18);
    b.insert_element(7);
    b.insert_element(28);
    b.insert_element(5);
    b.insert_element(15);
    b.insert_element(25);
    b.insert_element(19);
    b.insert_element(14);
    b.insert_element(40);
    b.insert_element(55);
    b.insert_element(42);
    b.insert_element(54);
    b.insert_element(3);
    b.insert_element(2);
    b.insert_element(26);

    b.inorder();

    b.delete_element(7);
    b.inorder();
    b.delete_element(28);
    b.inorder();

    b.delete_element(18);
    b.inorder();
    cout << "Height : " << b.get_height(b.root) << endl;

    return 0;
}