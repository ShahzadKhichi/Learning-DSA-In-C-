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
int main()
{
    Node *root = NULL;
    cout << "Enter Data for BTS : ";
    takeInput(root);
    cout << endl;
    cout << "printing in Pre Order : ";
    preOrder(root);
}