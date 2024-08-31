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

    cout << "Values     : ";
    for (int i = 0; head != NULL; i++)
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
    cout << "Size = " << count << endl;
    for (int i = 0; head != NULL; i++)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}
void insetAtTail(Node *&tail, Node *node)
{
    tail->next = new Node(node->data);
    tail = tail->next;
    tail->next = NULL;
}
void sort(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    Node *z_head = new Node(-1);
    Node *o_head = new Node(-1);
    Node *t_head = new Node(-1);
    Node *z_tail = z_head;
    Node *o_tail = o_head;
    Node *t_tail = t_head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insetAtTail(z_tail, temp);
        }
        else if (temp->data == 1)
        {
            insetAtTail(o_tail, temp);
        }
        else if (temp->data == 2)
        {
            insetAtTail(t_tail, temp);
        }
        Node *del = temp;
        temp = temp->next;
        delete del;
    }
    print(z_head);
    z_tail->next = o_head->next;
    z_tail = o_tail;
    print(z_head);
    z_tail->next = t_head->next;
    z_tail = t_tail;
    print(z_head);
    head = z_head->next;
    print(head);
    delete z_head;
    delete o_head;
    delete t_head;
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