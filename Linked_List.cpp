#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    return ;
}
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
    return ;
}
void insertAtMid(Node *head, int d, int position)
{
    int pos = 1;
    Node *temp = head;
    while (pos < (position - 1))
    {
        temp = temp->next;
        pos++;
        // cout << pos;
    }
    Node *NodeAtMid = new Node(d);
    NodeAtMid->next = temp->next;
    temp->next = NodeAtMid;
return ;
}
void print(Node *&head)
{
    Node *temp = head;
    while (head != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int main()
{
    Node *node1 = new Node(100);
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;

    // insertAtHead(head, 126);
    // insertAtHead(head, 127);
    // insertAtHead(head, 125);
    // print(head);
    insertAtTail(tail, 1);
    print(head);
    cout<<"HI"<<endl;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    
    insertAtMid(head, 222, 4);
    print(head);
    return 0;
}
