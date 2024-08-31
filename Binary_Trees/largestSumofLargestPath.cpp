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
void LargestSum(Node *&root, int len, int &lenMax, int sum, int &sumMax)
{
    if (root == NULL)
    {
        if (len > lenMax)
        {
            lenMax = len;
            sumMax = sum;
        }
        else if (len == lenMax)
        {
            sumMax = max(sum, sumMax);
        }
        return;
    }
    sum += root->data;
    LargestSum(root->left, len + 1, lenMax, sum, sumMax);
    LargestSum(root->right, len + 1, lenMax, sum, sumMax);
}
int main()
{
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 15 17 -1 -1 -1
    int sum = 0;
    int len = 0;
    root = buildTree(root);
    cout << endl;
    LargestSum(root, 0, len, 0, sum);
    cout << "Sum = " << sum << endl;
    return 0;
}