#include <iostream>
#include <vector>
#include <map>
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
vector<int> verticalTraverse(Node *&root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        Node *frontNode = q.front().first;
        int hd = q.front().second.first;
        int lvl = q.front().second.second;
        q.pop();
        nodes[hd][lvl].push_back(frontNode->data);
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    vector<int> ans = verticalTraverse(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}