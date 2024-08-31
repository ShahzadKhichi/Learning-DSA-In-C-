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
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    addNodeAtTail(tail, 2);
    addNodeAtPosition(head, tail, 3, 2);
    addNodeAtPosition(head, tail, 4, 3);
    addNodeAtPosition(head, tail, 5, 4);
    addNodeAtPosition(head, tail, 6, 5);
    print(head);
    check_loop(head);
    cout << "Size = " << Node::size << endl;
    deleteAll(head);
    return 0;
}