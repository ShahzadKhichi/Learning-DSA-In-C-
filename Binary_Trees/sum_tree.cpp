
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
pair<bool, int> sumFast(Node *&root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<int, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = sumFast(root->left);
    pair<bool, int> right = sumFast(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool result = (left.second + right.second) == root->data;
    pair<bool, int> ans;
    if (leftAns && rightAns && result)
    {
        ans = make_pair(true, 2 * root->data);
        return ans;
    }
    else
    {
        ans = make_pair(false, 0);
        return ans;
    }
}
bool sum(Node *&root)
{
    return (sumFast(root).first);
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "sum  Tree = " << sum(root) << endl;
    return 0;
}