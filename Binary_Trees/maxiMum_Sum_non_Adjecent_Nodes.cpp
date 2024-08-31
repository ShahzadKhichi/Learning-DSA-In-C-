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
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);

    pair<int, int> right = solve(root->right);

    pair<int, int> res = make_pair(root->data + left.second + right.second, left.first + right.first);
    return res;
}
int maxSum(Node *&root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
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
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 -1 17 -1 -1
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "maxSum = " << maxSum(root) << endl;
    return 0;
}