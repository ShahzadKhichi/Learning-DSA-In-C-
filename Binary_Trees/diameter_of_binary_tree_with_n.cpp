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
pair<int, int> daimeterFast(Node *&root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = daimeterFast(root->left);
    pair<int, int> right = daimeterFast(root->right);
    int leftAns = left.first;
    int rightAns = right.first;
    int height = left.second + right.second + 1;
    int old = max(max(leftAns, rightAns), height);
    pair<int, int> ans = make_pair(old, max(left.second, right.second) + 1);
    return ans;
}
int daimeter(Node *&root)
{
    pair<int, int> p = daimeterFast(root);
    int ans = max(p.first, p.second);
    return ans;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "Diameter of Tree = " << daimeter(root) << endl;
    return 0;
}