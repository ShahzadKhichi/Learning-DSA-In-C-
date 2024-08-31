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
bool validate(Node *root, int min = -2849523, int max = 2849523)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = validate(root->left, min, root->data);
        bool right = validate(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
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
Node *buildTree(Node *&root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for inseting in  left Node of  " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inseting in  right Node of  " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
int main()
{
    Node *root = NULL;
    // cout << "Enter data : ";

    // takeInput(root);
    buildTree(root);
    cout << "validation status :  " << validate(root) << endl;

    return 0;
}