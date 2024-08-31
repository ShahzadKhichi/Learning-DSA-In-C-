#include <iostream>
using namespace std;
class Node
{
public:
    int static size;
    int data;
    Node *next;
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
int Node ::size = 0;
void print(Node *head)
{

    cout << "Positions  : ";
    for (int i = 0; i < Node::size; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl
         << "Values     : ";
    for (int i = 0; i < Node::size; i++)
    {
        cout << head->data << " ";
        head = (head->next);
    }
    cout << endl;
}
void addNodeAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void addNodeAtTail(Node *&Tail, int data)
{
    Node *temp = new Node(data);
    Tail->next = temp;
    Tail = temp;
}
void addNodeAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        addNodeAtHead(head, data);
    }
    else if (position == Node::size)
    {
        addNodeAtTail(tail, data);
    }
    else if (position > 1 && position < Node::size)
    {
        int count = 1;
        Node *pre, *curr;
        pre = NULL;
        curr = head;
        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        Node *temp = new Node(data);
        pre->next = temp;
        temp->next = curr;
    }
    else
    {
        cout << "Invalid Positon " << endl;
    }
}
void deleNodeAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else if (position == Node::size)
    {
        Node *temp = head;
        Node *pre = temp;
        while (temp->next != NULL)
        {
            pre = temp;
            temp = (temp->next);
        }
        delete tail;
        tail = pre;
        tail->next = NULL;
    }
    else if (position > 1 && position < Node::size)
    {
        int count = 1;
        Node *pre, *curr;
        pre = NULL;
        curr = head;
        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        pre->next = curr->next;
        delete curr;
    }
    else
    {
        cout << "Invalid Positon " << endl;
    }
}
void deleteAll(Node *&head)
{

    int count = Node::size;
    for (int i = 0; i < count; i++)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}
void sort(Node *&head)
{
    Node *temp = head;
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeros++;
        }
        else if (temp->data == 1)
        {
            ones++;
        }
        else if (temp->data == 2)
        {
            twos++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeros != 0)
        {
            temp->data = 0;
            zeros--;
        }
        else if (ones != 0)
        {
            temp->data = 1;
            ones--;
        }
        else if (twos != 0)
        {
            temp->data = 2;
            twos--;
        }
        temp = temp->next;
    }
}
int main()
{
    Node *n1 = new Node(0);
    Node *head = n1;
    Node *tail = n1;
    addNodeAtTail(tail, 2);
    addNodeAtHead(head, 1);
    addNodeAtPosition(head, tail, 1, 2);
    addNodeAtPosition(head, tail, 1, 4);
    addNodeAtPosition(head, tail, 2, 5);
    addNodeAtPosition(head, tail, 2, 3);
    print(head);
    sort(head);
    print(head);
    deleteAll(head);
    return 0;
}