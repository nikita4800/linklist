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
void insertatstart(Node*&head,int data)
{
    Node*n=new Node(data);

    n->next=head;
    if(head!=NULL)
    {
    head->pre=n;
    }
    head=n;
}
void inseratend(Node*&head,int data)
{
    Node*n=new Node(data);
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->pre=temp;
    n=NULL;
    
}
void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertatposition(Node*&head,int position,int data)
{
    Node*n=new Node(data);
    Node*temp=head;
    while(temp->data!=position)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next->pre=n;
    temp->next=n;
    n->pre=temp;

}
void deleteatbeg(Node*&head)
{
   Node*n=head;
   if(head==NULL)
   {
    cout<<"cant delet node because the linklist is empty"<<endl;
   }
   else
   {
    head=head->next;
    free(n);
   }
}
void deleteatend(Node*&head)
{
    Node*temp=head;
    Node*flag=head;
    if(head==NULL)
    {
       cout<<"cant delet node because the linklist is empty"<<endl;
    }
    else
    {
        while(temp->next!=NULL)
        {
            flag=temp;
            temp=temp->next;
        }
        flag=NULL;
        free(temp);
         }
}
void deleteatmid(Node*&head,int position)
{
    Node*temp=head;
    Node*flag=head;
    if(head==NULL)
    {
       cout<<"cant delet node because the linklist is empty"<<endl;
    }
    else
    {
       while(temp->data!=position)
       {
        flag=temp;
        temp=temp->next;
       }
       flag->next=temp->next;
       temp->next->pre=flag;
       free(temp);
    }
}
int main()
{
  Node*head=NULL;

  insertatstart(head,1);
  insertatstart(head,2);
  insertatstart(head,3);
  insertatstart(head,4);
   print(head);
  inseratend(head,5);
   print(head);
  insertatposition(head,2,2);
   print(head);
  deleteatbeg(head);
   print(head);
  deleteatend(head);
   print(head);
  deleteatmid(head,2);

  print(head);
}