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
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (left != NULL)
    {
        return left;
    }
    else if (right != NULL)
    {
        return right;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    Node *lc = lca(root, 11, 1);
    if (lc != NULL)
        cout << "LCA = " << lc->data << endl;
    else
    {
        cout << "There is no LCA " << endl;
    }
    return 0;
}