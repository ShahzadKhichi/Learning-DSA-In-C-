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
void buildTree(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter data for left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Enter data for right of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    buildTree(root);
    levelOrderTraversal(root);
    return 0;
}