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
Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *pre, *curr, *next;
    pre = NULL;
    curr = head;
    next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
Node *solve(Node *first, Node *second)
{
    Node *ans = NULL;
    int carry = 0;
    while (first != NULL || second != NULL)
    {
        int a = 0;
        int b = 0;
        if (first != NULL)
        {
            a = first->data;
            first = first->next;
        }
        if (second != NULL)
        {
            b = second->data;
            second = second->next;
        }
        int c = a + b + carry;
        int digit = c % 10;
        carry = c / 10;
        addNodeAtHead(ans, digit);
    }
    return ans;
}
Node *Add(Node *head1, Node *head2)
{
    Node *ans;
    head1 = reverse(head1);
    head2 = reverse(head2);
    ans = solve(head1, head2);
    return ans;
}
int main()
{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    addNodeAtTail(tail, 2);
    addNodeAtHead(head, 1);
    print(head);
    Node *n2 = new Node(5);
    Node *head_1 = n2;
    Node *tail_1 = n2;
    addNodeAtTail(tail_1, 0);
    addNodeAtTail(tail_1, 0);
    print(head_1);
    cout << "Sign       : + " << endl;
    Node *temp = head_1;
    print(Add(head_1, head));
    // deleteAll(head);
    return 0;
}