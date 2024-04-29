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
//to print middle element of singly link list
 void midelement(Node*&head)
{
     
     Node*slow=head;
     Node*fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

    }
   cout<<"the middle element is "<<slow->data<<endl;

}
//reverse a link list
void reverse_linklist(Node*&head)
{
    Node*pre=NULL;
    Node*current=head;
    Node*next;
    while(current!=NULL)
   {
    next=current->next;
    current->next=pre;
    pre=current;
    current=next;
   }
head=pre;
}
// Nth node from the end of a Linked List

// Input: 1 -> 2 -> 3 -> 4, N = 3
// Output: 2

// Input: 35 -> 15 -> 4 -> 20, N = 4
// Output: 35  
void length(Node*&head, int N)
{
    int len=0,i;
    Node*temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    if(len<N)
    {
        return;
    }
    temp=head;
    for(i=1;i<len-N+1;i++)
    {
        temp=temp->next;
    }
    cout<<temp->data;
    return;

}
//Remove duplicates from a sorted linked list

void remove_dublicate(Node*&head)
{
    Node*current=head;
    Node*next_next;
    if(current==NULL)
    {
        return;
    }
   while(current->next!=NULL)
   {
    if(current->data==current->next->data)
    {
        next_next=current->next->next;
        free(current->next);
        current->next=next_next;
    }
    else{
        current=current->next;
    }
   }

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
  midelement(head);
   reverse_linklist(head);
print (head);
length(head,2);
remove_dublicate(head);
print(head);

}