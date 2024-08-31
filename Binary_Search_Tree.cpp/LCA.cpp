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
Node *solve(Node *root, int p, int q)
{
    while (root != NULL)
    {
        if (root->data > p && root->data > q)
        {
            root = root->left;
        }
        else if (root->data > p && root->data > q)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter Data for BTS : ";
    takeInput(root);
    cout << endl;
    int p, q;
    cout << " Enter P : ";
    cin >> p;
    cout << "Enter Q :";
    cin >> q;
    Node *LCA = solve(root, p, q);
    if (LCA)
    {
        cout << "LCA : " << LCA->data << endl;
    }
    else
    {
        cout << "NO LCA Exist : ";
    }
}
