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
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }

    }
};

void printNode(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head,int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertAtMid(Node *&head,Node* &tail , int data, int position)
{
    if(position==1)
    {
        insertAtHead(head,data);
    }
    Node *temp = head;
    int count = 1;
    while (count < (position-1))
    {
        temp=temp->next;
        count++;
    }
    
    if(temp->next==NULL)
    {
        insertAtTail(tail,data);
        return;
    }
    Node* atmid=new Node(data);
    atmid->next=temp->next;
    temp->next=atmid;

}
void deletenode(Node* &head,Node* &tail,int position)
{
    if(position==1)
    {
        Node* temp= head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        
        Node* prev=NULL;
        Node* curr=head;
        int count=1;
        while (count <position)
        {
            prev=curr;
            curr=curr->next;
            count++;
            // cout<<"else  "<<count<<endl;
        }
        if(curr->next==NULL)
        {
            tail=prev;
        }
        prev->next=curr->next;//moving the pointer forward
        curr=NULL;
        
        delete curr;
    }
}
int main()
{
    Node *new1 = new Node(15);
    Node *head = new1;
    Node *tail = new1;
    insertAtHead(head, 25);
    printNode(head);
    insertAtHead(head, 55);
    printNode(head);
    insertAtTail(tail, 65);
    printNode(head);
    insertAtMid(head,tail,11,5);
    printNode(head);
    deletenode(head,tail,1);
    printNode(head);
    deletenode(head,tail,3);
    printNode(head);
    deletenode(head,tail,3);
    printNode(head);
    cout<<"head"<<head->data<<endl;
    cout<<"Tail"<<tail->data<<endl;
   

    return 0;
}
