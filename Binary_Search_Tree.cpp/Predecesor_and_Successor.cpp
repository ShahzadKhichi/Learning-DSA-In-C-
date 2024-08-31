#include <iostream>
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
Node *insertNode(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data >= data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertNode(root, data);
        cin >> data;
    }
}
pair<int, int> solution(Node *&root, int n)
{
    int pred, suces;
    Node *temp = root;
    pred = -1;
    suces = -1;
    while (temp->data != n)
    {
        if (temp->data > n)
        {
            suces = temp->data;
            temp = temp->left;
        }
        else if (temp->data < n)
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    Node *left = temp->left;
    Node *right = temp->right;
    while (left != NULL)
    {
        pred = left->data;
        left = left->right;
    }
    while (right != NULL)
    {
        suces = right->data;
        right = right->left;
    }
    return {pred, suces};
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    cout << endl;
    int n;
    cout << "Enter Node : ";
    cin >> n;
    pair<int, int> ans = solution(root, n);
    cout << "Predecssor : " << ans.first << endl;
    cout << "Successor : " << ans.second << endl;
    return 0;
}