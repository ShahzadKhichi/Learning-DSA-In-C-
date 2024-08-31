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
Node *slove(Node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }

    Node *left = slove(root->left, k, n);
    Node *right = slove(root->right, k, n);

    if (left != NULL)
    {
        if (k == 0)
        {
            k = 10000000;
            return left;
        }
        k--;
        return root;
    }
    if (right != NULL)
    {
        if (k == 0)
        {
            k = 10000000;
            return right;
        }
        k--;
        return root;
    }
    return NULL;
}
int kth_Ancestor(Node *&root, int k, int n)
{
    if (root == NULL || root->data == n)
    {
        return -1;
    }
    Node *ans = slove(root, k, n);
    if (ans != NULL)
        return ans->data;
    else
        return -1;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "Kth_Ancesstor = " << kth_Ancestor(root, 1, 17) << endl;
    return 0;
}