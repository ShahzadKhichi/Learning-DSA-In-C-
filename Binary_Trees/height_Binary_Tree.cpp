#include <iostream>
#include <queue>
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
int height(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int height = max(left, right) + 1;
    return height;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "Height of Tree = " << height(root) << endl;
    return 0;
}