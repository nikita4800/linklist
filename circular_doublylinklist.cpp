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
    this->next=NULL;
    this->pre=NULL;
}
};
void insertatbeg(Node*&head,int data)
{   Node*temp=head;
    Node*n=new Node(data);
    if(head==NULL)
    {
        head=n;
        n->next=head;
        n->pre=head;
        return;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
     n->pre=temp;
   head=n;
}
void insertatend(Node*&head,int data)
{   Node*temp=head;
    Node*n=new Node(data);
    if(head==NULL)
    {
        head=n;
        n->next=head;
        n->pre=head;
        return;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head->pre=n;
    n->pre=temp;
}
void print(Node*head)
{
    Node*temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
}
void insertatmid(Node*&head,int position,int data)

{
    Node*temp=head;
   Node*n=new Node(data);
   if(head==NULL)
    {
        head=n;
        n->next=head;
        n->pre=head;
        return;
    }
    while(temp->data!=position)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next->pre=n;
    n->pre=temp;
    temp->next=n;
}
void deleteatbeg(Node*&head)
{
   Node*n=head;
     Node*temp=head;
   if(head==NULL)
   {
    cout<<"the list is empty cannot deletee"<<endl;
   }
   while(temp->next!=head)
   {
    temp=temp->next;
   }
   head=head->next;
   temp->next=head;
   head->pre=temp;
   free(n);
}
void deleteatend(Node*&head)
{
     Node*n=head;
     Node*temp=head;
   if(head==NULL)
   {
    cout<<"the list is empty cannot deletee"<<endl;
   }
   while(temp->next!=head)
   {
    n=temp;
    temp=temp->next;
   }
   n->next=head;
   head->pre=n;
   free(temp);
}
void deleteatmid(Node*&head,int position)
{
     Node*n=head;
     Node*temp=head;
   if(head==NULL)
   {
    cout<<"the list is empty cannot deletee"<<endl;
   }
   while(temp->data!=position)
   {
    n=temp;
    temp=temp->next;
   }
   n->next=temp->next;
   temp->next->pre=n;
   free(temp);
}
int main()
{
   Node*head=NULL;
   insertatbeg(head,1);
   insertatbeg(head,2);
   insertatbeg(head,3);
   insertatbeg(head,4);
   insertatbeg(head,5);

insertatend(head,0);
insertatmid(head,3,3);
print(head);
deleteatbeg(head);
   print(head);
   deleteatend(head);
   print(head);
   deleteatmid(head,3);
print(head);

}