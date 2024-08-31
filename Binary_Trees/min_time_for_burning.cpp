#include <iostream>
#include <queue>
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
Node *creatMap(Node *root, int n, map<Node *, Node *> &m)
{
    queue<Node *> q;
    q.push(root);
    Node *node;
    m[root] = NULL;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front && front->data == n)
        {
            node = front;
        }
        if (front->left)
        {
            m[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            m[front->right] = front;
            q.push(front->right);
        }
    }
    return node;
}
int solve(Node *target, map<Node *, Node *> &parent)
{
    int ans = 0;
    map<Node *, bool> visited;
    visited[target] = 1;
    queue<Node *> q;
    q.push(target);
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left])
            {
                flag = 1;
                q.push(curr->left);
                visited[curr->left] = 1;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                flag = 1;
                visited[curr->right] = 1;
            }
            if (parent[curr] && !visited[parent[curr]])
            {
                flag = 1;
                q.push(parent[curr]);
                visited[parent[curr]] = 1;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int n)
{
    map<Node *, Node *> currToparent;
    Node *target = creatMap(root, n, currToparent);
    int ans = solve(target, currToparent);
    return ans;
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    root = buildTree(root);
    cout << endl;
    cout << "Minium Time = " << minTime(root, 6) << endl;
    return 0;
}
