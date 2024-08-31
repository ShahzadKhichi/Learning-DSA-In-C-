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
bool identical(Node *&root1, Node *&root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);
    cout << endl;
    cout << "root 1 : " << root1->data << endl;
    cout << "root 2 : " << root2->data << endl;
    if (root1->data == root2->data && left && right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node *root1;
    Node *root2;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    cout << "Enter data for root 1 : \n";
    root1 = buildTree(root1);
    cout << "\nEnter data for root 2 : \n";
    root2 = buildTree(root2);
    cout << "\nidentical of Tree = " << identical(root1, root2) << endl;
    return 0;
}