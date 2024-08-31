#include <iostream>
using namespace std;
class Node
{
public:
    int static size;
    int data;
    Node *next;
    Node *rand;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        rand = NULL;
        size++;
    }
    ~Node()
    {
        size--;
    }
};
int Node ::size = 0;
void print(Node *org)
{
    Node *head = org;
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
    if (Tail == NULL)
    {
        Tail = new Node(data);
        return;
    }
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
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
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
void deleteAll(Node *&head, Node *&tail)
{

    while (head != NULL)
    {
        deleNodeAtPosition(head, tail, 1);
    }
}
void merge(Node *&org, Node *&clone)
{
    Node *cur1 = org;
    Node *cur2 = clone;
    Node *next1;
    Node *next2;
    while (cur1 != NULL && cur2 != NULL)
    {
        next1 = cur1->next;
        cur1->next = cur2;
        next2 = cur2->next;
        cur2->next = next1;
        cur1 = next1;
        cur2 = next2;
    }
    return;
}

Node *clone(Node *&head)
{
    Node *clone = NULL;
    Node *temp;
    int count = 1;
    Node *org = head;
    while (org != NULL)
    {

        addNodeAtTail(clone, org->data);
        if (count == 1)
        {
            temp = clone;
        }
        count++;
        org = org->next;
    }
    org = head;
    clone = temp;
    merge(org, clone);
    org = head;
    while (org != NULL)
    {
        if (org->next != NULL)
        {
            org->next->rand = org->rand ? org->rand->next : NULL;
        }
        org = org->next->next;
    }
    clone = temp;
    org = head;

    while (org != NULL && clone != NULL)
    {
        org->next = clone->next;
        org = org->next;
        if (org != NULL)
            clone->next = org->next;
        clone = clone->next;
    }
    return temp;
}
int main()
{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    addNodeAtTail(tail, 2);
    addNodeAtHead(head, 1);
    addNodeAtPosition(head, tail, 1, 2);
    addNodeAtPosition(head, tail, 1, 4);
    addNodeAtPosition(head, tail, 2, 5);
    addNodeAtPosition(head, tail, 3, 3);
    head->rand = head->next->next;
    print(head);
    cout << "Random org = " << head->rand->data << endl;
    Node *cl = clone(head);
    cout << "Random clo = " << cl->rand->data << endl;
    cout << "size = " << Node::size << endl;
    deleteAll(head, tail);
    deleteAll(cl, cl);
    cout << "size = " << Node::size << endl;
    return 0;
}