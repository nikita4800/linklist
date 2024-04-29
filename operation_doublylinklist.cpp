#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*pre;

    Node(int data)
    {
        this->data=data;
        Node*next=NULL;
        Node*pre=NULL;
    }
};
void insertatbeg(Node*&head,int data)
{
    Node*n=new Node(data);
     n->next=head;
    if(head!=NULL)
    {
       head->pre=n; 
    }
     head=n;
}
//reverse the doubly link list 
void reverse(Node*&head) {
    Node* current = head;
    Node* temp = NULL;
    Node*pre;

 
    while (current != NULL) {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;
    }
 
    if (temp != NULL) {
        head = temp->pre;
    }
}

void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
  Node*head=NULL;
  insertatbeg(head,1);
  insertatbeg(head,2);
  insertatbeg(head,3);
  insertatbeg(head,4);

  print(head);
  reverse(head);
  print(head);
}