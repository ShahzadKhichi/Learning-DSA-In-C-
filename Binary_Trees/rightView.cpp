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
vector<int> topView(Node *&root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        Node *frontNode = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if (nodes.find(lvl) == nodes.end())
        {
            nodes[lvl] = (frontNode->data);
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, (lvl + 1)));
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, lvl + 1));
        }
        }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    root = buildTree(root);
    cout << endl;
    vector<int> ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}