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
    this->next=NULL;
  }
};
void insertatbeg(Node*&head,int data)
{
    Node*n=new Node(data);
    if(head==NULL)
    {
        head=n;
        n->next=n;
        return;
    }
        Node*temp3=head;
        while(temp3->next!=head)
        {
            temp3=temp3->next;
        }
        temp3->next=n;
        n->next=head;
        head=n;
    
}
void insertatmid(Node*&head,int position,int data)
{
    Node*flag=new Node(data);
    Node*temp3=head;
    while(temp3->data!=position)
    {
        temp3=temp3->next;
    }
    flag->next=temp3->next;
    temp3->next=flag;

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
void insertatend(Node*&head,int data)
{
    Node*temp3=head;
    Node*flag=new Node(data);
    while(temp3->next!=head)
    {
        temp3=temp3->next;
    }
    temp3->next=flag;
    flag->next=head;
}
void deletatbeg(Node*&head)
{
  Node*flag=head;
  Node*temp3=head;
  while(temp3->next!=head)
  {
    temp3=temp3->next;
  }
  head=head->next;
  temp3->next=head;
  free(flag);
}
void deletatend(Node*&head)
{
    Node*temp3=head;
    Node*flag=head;
    while(temp3->next!=head)
    {
        flag=temp3;
        temp3=temp3->next;
    }
    flag->next=head;
    free(temp3);
}
int main()
{
Node*head=NULL;
insertatbeg(head,1);
insertatbeg(head,2);
insertatbeg(head,3);
insertatbeg(head,4);
print(head);
insertatmid(head,2,5);
print(head);
insertatend(head,0);
print(head);
deletatbeg(head);
print(head);
deletatend(head);
print(head);
}