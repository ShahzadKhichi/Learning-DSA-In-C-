#include <iostream>
#include <map>
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
void createMap(int in[], int n, map<int, int> &m)
{
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
}
Node *solve(int in[], int pre[], int n, int start, int end, int &index, map<int, int> &m)
{
    if (index >= n || start > end)
    {
        return NULL;
    }

    int element = pre[index++];
    int position = m[element];
    Node *root = new Node(element);

    root->left = solve(in, pre, n, start, position - 1, index, m);
    root->right = solve(in, pre, n, position + 1, end, index, m);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int index = 0;
    map<int, int> m;
    createMap(in, n, m);
    Node *ans = solve(in, pre, n, 0, n - 1, index, m);
    return ans;
}
void post_order(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}
int main()
{
    int in[4] = {1, 6, 8, 7};
    int pre[4] = {1, 6, 7, 8};
    int n = 4;
    Node *root = buildTree(in, pre, n);
    cout << endl;
    post_order(root);
    return 0;
}