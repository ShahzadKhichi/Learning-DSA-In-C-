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
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
bool search(Node *root, int element)
{
    while (root != NULL)
    {
        if (root->data == element)
        {
            return true;
        }
        if (root->data > element)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
int main()
{
    Node *root = NULL;
    int n;
    cout << "Enter Data for BTS : ";
    takeInput(root);
    cout << endl;
    cout << "printing in Pre Order : ";
    preOrder(root);
    cout << endl
         << "Enter element to search : ";
    cin >> n;
    cout << "status  : " << search(root, n) << endl;
}