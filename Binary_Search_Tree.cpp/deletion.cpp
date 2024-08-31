#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *insertNode(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data >= data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertNode(root, data);
        cin >> data;
    }
}
int min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
Node *del(Node *&root, int element)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == element)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int mini = min(root->right);
            root->data = mini;
            root->right = del(root->right, mini);
        }
    }
    if (root->data > element)
    {
        root->left = del(root->left, element);
    }
    else
    {
        root->right = del(root->right, element);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int n;
    cout << "Enter Data for BTS : ";
    takeInput(root);
    cout << endl;
    cout << "printing in In Order : ";
    inOrder(root);
    cout << "\nEnter element to del : ";
    cin >> n;
    root = del(root, n);
    cout << endl;
    cout << "printing in In Order : ";
    inOrder(root);
}