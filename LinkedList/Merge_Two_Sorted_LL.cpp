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
    for (int i = 0; head != NULL; i++)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}
Node *solve(Node *first, Node *second)
{
    Node *curr1 = first;
    Node *next1 = first->next;
    Node *curr2 = second;
    Node *next2 = second->next;
    if (first->next == NULL && second->next == NULL)
    {
        first->next = second;
        return first;
    }
    while (curr1 != NULL && curr2 != NULL)
    {

        if (next1 == NULL)
        {
            curr1->next = curr2;
            return first;
        }
        if (next2 == NULL)
        {
            return first;
        }
        if (curr2->data >= curr1->data && curr2->data < next1->data)
        {
            curr1->next = curr2;
            curr2 = curr2->next;
            next2 = next2->next;
            curr1->next->next = next1;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
        }
        if (next1 != NULL && next2 != NULL)
        {
            cout << "curr1 = " << curr1->data << " : ";
            cout << "next1 = " << next1->data << endl;
            cout << "curr2 = " << curr2->data << " : ";
            cout << "next2 = " << next2->data << endl;
        }
    }
    return first;
}
Node *merge(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data < second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
int main()
{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    addNodeAtTail(tail, 2);
    addNodeAtPosition(head, tail, 4, 2);
    addNodeAtPosition(head, tail, 6, 3);
    addNodeAtPosition(head, tail, 8, 4);
    print(head);
    Node *n2 = new Node(5);
    Node *head_1 = n2;
    Node *tail_1 = n2;
    addNodeAtTail(tail_1, 7);
    addNodeAtTail(tail_1, 9);
    print(head_1);
    Node *aft = merge(head_1, head);
    print(aft);
    return 0;
}