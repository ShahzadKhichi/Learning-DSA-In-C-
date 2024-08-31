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
void print(vector<int> v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<int> zig_zag_traversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;
            cout << ans[index] << endl;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        leftToRight = (!leftToRight);
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    // 1 2 -1 -1 3 4 -1 -1 5 -1 -1
    root = buildTree(root);
    cout << endl;
    print(zig_zag_traversal(root));
    return 0;
}