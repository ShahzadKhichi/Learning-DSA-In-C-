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
Node *solve(int in[], int post[], int n, int start, int end, int &index, map<int, int> &m)
{
    if (index < 0 || start > end)
    {
        return NULL;
    }
    int element = post[index--];
    int position = m[element];
    Node *root = new Node(element);
    root->right = solve(in, post, n, position + 1, end, index, m);
    root->left = solve(in, post, n, start, position - 1, index, m);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int index = n - 1;
    map<int, int> m;
    createMap(in, n, m);
    Node *ans = solve(in, post, n, 0, n - 1, index, m);
    return ans;
}
void pre_order(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}
int main()
{
    int in[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[8] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    Node *root = buildTree(in, post, n);
    cout << endl;
    pre_order(root);
    return 0;
}