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
int kth_smallest(Node *root, int k, int &i)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = kth_smallest(root->left, k, i);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return kth_smallest(root->right, k, i);
}
int main()
{
    Node *root = NULL;
    cout << "Enter data : ";
    takeInput(root);
    int i = 0;
    int k;
    cout << "Enter k : ";
    cin >> k;
    cout << "Kth smallest : " << kth_smallest(root, k, i) << endl;
    return 0;
}