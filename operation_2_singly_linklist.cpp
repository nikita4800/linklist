#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;

    Node(int data)
    {
       this->data=data;
       Node*next=NULL;
    }
};
//singly link list
void insertatbeg(Node*&head,int data)
{
    Node*n=new Node(data);
    n->next=head;
    head=n;
}
void print(Node*&head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<"->";
       temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//Detect loop or cycle in a linked list
void cycle(Node*&head)
{
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next==NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            cout<<"the loop is cycle"<<endl;
        }
    }
cout<<"the loop is NOT cycle"<<endl;
}

int main()
{
  Node*head=NULL;
  insertatbeg(head,2);
  insertatbeg(head,2);
  insertatbeg(head,3);
  insertatbeg(head,4);
  insertatbeg(head,4);
  insertatbeg(head,5);
    print (head);
    cycle(head);
  

}