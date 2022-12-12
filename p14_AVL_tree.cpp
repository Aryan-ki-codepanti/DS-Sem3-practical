#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int a)
    {
        data = a;
        left = right = NULL;
    }
};

class AVL_Tree
{
public:
    Node *root;
    AVL_Tree()
    {
        root = NULL;
    }

    Node *largest_node(Node *node)
    {
        Node *ptr = node;
        while (ptr->right != NULL)
            ptr = ptr->right;
        return ptr;
    }

    int get_height(Node *node)
    {
        if (node == NULL)
            return -1;
        int left_height = get_height(node->left);
        int right_height = get_height(node->right);
        return max(left_height, right_height) + 1;
    }

    int get_balance_factor(Node *node)
    {
        if (node == NULL)
            return -1;
        return get_height(node->left) - get_height(node->right);
    }

    // x is root of prob
    Node *right_rotate(Node *x)
    {
        Node *y = x->left;
        Node *T2 = y->right;

        y->right = x;
        x->left = T2;
        return y;
    }
    Node *left_rotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;
        return y;
    }

    void inorder_recursive(Node *node)
    {
        if (node == NULL)
            return;
        inorder_recursive(node->left);
        cout << node->data << " ";
        inorder_recursive(node->right);
    }

    Node *insert_element_recursive(Node *node, int a)
    {
        if (node == NULL)
            return new Node(a);

        else if (node->data > a)
            node->left = insert_element_recursive(node->left, a);

        else if (node->data < a)
            node->right = insert_element_recursive(node->right, a);

        else
            cout << "Duplicates not allowed" << endl;

        // rebalancing from leaves
        int bf = get_balance_factor(node);

        // LL rotation
        if (bf > 1 && a < node->left->data)
        {
            return right_rotate(node);
        }

        // RR rotation
        else if (bf < -1 && a > node->right->data)
        {
            return left_rotate(node);
        }

        // LR rotation
        else if (bf > 1 && a > node->left->data)
        {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        // RL rotation
        else if (bf < -1 && a < node->right->data)
        {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    Node *delete_element_recursive(Node *node, int a)
    {

        // Node not found
        if (node == NULL)
        {

            cout << a << " not found" << endl;
            return NULL;
        }

        else if (node->data > a)
            node->left = delete_element_recursive(node->left, a);

        else if (node->data < a)
            node->right = delete_element_recursive(node->right, a);

        // Deletion :  node is the node to be deleted
        else
        {
            // no child
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            // one child (right)
            if (node->left == NULL)
            {
                Node *tmp = node->right;
                delete node;
                return tmp;
            }
            // one child (left)
            if (node->right == NULL)
            {
                Node *tmp = node->left;
                delete node;
                return tmp;
            }

            // two children
            Node *largest = largest_node(node->left);
            node->data = largest->data;
            node->left = delete_element_recursive(node->left, largest->data);
        }

        // rebalancing from leaves
        int bf = get_balance_factor(node);

        // deletion from  right subtrees
        // LL rotation
        if (bf > 1 && get_balance_factor(node->left) >= 0)
        {
            return right_rotate(node);
        }

        // LR rotation
        else if (bf > 1 && get_balance_factor(root->left) < 0)
        {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        // from left subtrees
        //  RR rotation
        else if (bf < -1 && get_balance_factor(node->right) <= 0)
        {
            return left_rotate(node);
        }

        // RL rotation
        else if (bf < -1 && get_balance_factor(node->right) <= 0)
        {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    void inorder()
    {
        inorder_recursive(root);
        cout << endl;
    }

    void insert_element(int a)
    {
        root = insert_element_recursive(root, a);
    }

    void delete_element(int a)
    {
        root = delete_element_recursive(root, a);
    }
};

int main()
{
    AVL_Tree t;
    t.insert_element(3);
    t.insert_element(3);
    t.insert_element(6);
    t.insert_element(1);
    t.insert_element(2);
    t.insert_element(8);
    t.insert_element(5);
    t.inorder();
    t.delete_element(5);
    t.delete_element(0);
    t.delete_element(3);
    t.inorder();
    return 0;
}