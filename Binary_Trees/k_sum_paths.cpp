#include <iostream>
#include <vector>
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
void solve(Node *root, int k, int &count, vector<int> v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    solve(root->left, k, count, v);
    solve(root->right, k, count, v);
    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i];
        if (sum == k)
        {
            count++;
        }
    }
    v.pop_back();
}
int kSumPaths(Node *&root, int k)
{
    int count = 0;
    if (root == NULL)
    {
        return count;
    }
    vector<int> v;
    solve(root, k, count, v);
    return count;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "Number of paths for 10 sum " << kSumPaths(root, 15) << endl;
    return 0;
}