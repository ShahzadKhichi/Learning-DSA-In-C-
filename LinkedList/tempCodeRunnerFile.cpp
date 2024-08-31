#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *pre, *next;
    int static size;
    Node(int data)
    {
        this->data = data;
        pre = NULL;
        next = NULL;
        size++;
    }
    ~Node()
    {
        size--;
    }
};
int Node::size = 0;
void print(Node *head)
{
    for (; head != NULL;)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void insertHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}
void insertTail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
        head = tail;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertHead(head, tail, data);
    }
    else if (position == (Node::size))
    {
        insertTail(tail, head, data);
    }
    else
    {
        // cout << "Size = " << Node::size << endl;
        Node *temp = new Node(data);
        Node *pre, *curr, *next;
        pre = NULL;
        curr = head;
        next = head->next;
        int count = 1;
        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            next = next->next;
            count++;
        }
        temp->next = curr;
        temp->pre = curr->pre;
        temp->pre->next = temp;
        curr->pre = temp;
    }
}
void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->pre = NULL;
        delete temp;
    }
    else if (position == Node::size)
    {
        Node *temp = tail;
        tail = tail->pre;
        tail->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head, *pre = NULL;
        int count = 1;
        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        pre->next = curr->next;
        curr->next->pre = pre;
        delete curr;
    }
}
void deleteALL(Node *&head, Node *&tail)
{
    int count = 1;
    while (head != NULL)
    {
        deleteAtPosition(head, tail, count);
        head = head->next;
    }
}
int main()
{
    // Node *node = new Node(1);
    Node *head = NULL;
    Node *tail = NULL;
    insertTail(tail, head, 2);
    insertHead(head, tail, 1);
    insertTail(tail, head, 3);
    insertAtPosition(head, tail, 4, 3);
    insertAtPosition(head, tail, 5, 4);
    print(head);
    insertAtPosition(head, tail, 6, 5);
    print(head);
    deleteALL(head, tail);
    cout << "size = " << Node::size << endl;
    return 0;
}