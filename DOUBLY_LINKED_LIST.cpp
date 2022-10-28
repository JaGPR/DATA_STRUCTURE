#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void printdl(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getlength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    // cout<<endl;
    return count;
}
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtMid(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int count = 1;
        while (count < (position))
        {
            // cout<<count<<endl;
            prev = curr;
            curr = curr->next;
            count++;
            // cout<<curr->next<<endl;
        }
        if (curr->next == NULL)
        {
            insertAtTail(tail, data);
            return;
        }
        Node *temp = new Node(data);
        temp->prev = curr;
        temp->next = curr->next;
        (curr->next)->prev = temp->next;
    }
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)

    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int pos = 1;
        while (pos <= (position - 1))
        {
            prev = curr;
            curr = curr->next;
            pos++;
            cout << pos << endl;
            // cout<<curr->data<<endl;
        }
        if (curr->next == NULL)
        {
            // cout<<prev->data<<endl;
            curr->prev = NULL;
            prev->next = NULL;
            // cout<<prev->next<<endl;
            tail = prev;
            cout<<tail->data<<endl;
            delete curr;
            cout << "deletion done" << endl;
            return;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next->prev=prev;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node *new1 = new Node(10);
    Node *head = new1;
    Node *tail = new1;
    printdl(head);
    // cout<<getlength(head);
    insertAtHead(head, 15);
    insertAtTail(tail, 55);
    printdl(head);
    insertAtMid(head, tail, 5958, 3);
    printdl(head);
    cout << "Head data" << head->data << endl;
    cout << "Head data" << tail->data << endl;
    deleteNode(head, tail, 3);
    printdl(head);
    return 0;
}
