#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    int static size;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        size++;
    }
    ~Node()
    {
        size--;
    }
};
int Node::size = 0;
void print(Node *tail)
{
    int count = Node::size;
    for (int i = 0; i < count; i++)
    {
        cout << tail->next->data << " ";
        tail = tail->next;
    }
    cout << endl;
}
void insertNode(Node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        tail->next = tail;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}
void insertAtPosition(Node *&tail, int data, int position)
{
    if (position == 1)
    {
        Node *temp = new Node(data);
        temp->next = tail->next;
        tail->next = temp;
    }
    else if (position == Node::size)
    {
        insertNode(tail, data);
    }
    else
    {
        Node *temp = new Node(data);
        int count = 1;
        Node *curr, *pre;
        pre = tail;
        curr = tail->next;
        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        pre->next = temp;
        temp->next = curr;
    }
}
void delete_Node(Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }
    else if (position == Node::size)
    {
        Node *temp = tail->next;
        int count = 1;
        Node *curr, *pre;
        pre = tail;
        curr = tail->next;
        while (count < (Node::size)-1)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        curr->next = tail->next;
        delete tail;
        tail = curr;
    }
    else
    {
        Node *temp = tail->next;
        int count = 1;
        Node *curr, *pre;
        pre = tail;
        curr = tail->next;
        while (count < (Node::size)-1)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        pre->next = curr->next;
        delete curr;
    }
}
void check_loop(Node *&head)
{

    if (head == NULL)
    {
        cout << "Circluar " << endl;
        return;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        cout << "Circluar " << endl;
    }
    else
    {
        cout << "Not Circluar " << endl;
    }
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 1);
    print(tail);
    insertNode(tail, 2);
    print(tail);
    insertNode(tail, 3);
    print(tail);
    insertAtPosition(tail, 0, 1);
    print(tail);
    insertAtPosition(tail, 4, 4);
    print(tail);

    delete_Node(tail, 1);
    print(tail);
    delete_Node(tail, 4);
    print(tail);
    delete_Node(tail, 2);
    print(tail);
    delete_Node(tail, 2);
    print(tail);
    check_loop(tail);
    return 0;
}