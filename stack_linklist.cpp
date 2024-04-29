#include<iostream>
using namespace std;
//stack using link list
class Node
{
    public:
    int data;
    Node*next;
};
class stack
{
    Node*top;
    public:
    stack()
    {
        top=NULL;
    }
  void push(int x)
{
    Node*n=new Node();
    n->data=x;
    n->next=top;
    top=n;
}
void pop()
{
    if(top==NULL)
    {
        cout<<"stack is underflow"<<endl;
    }
    else
    {
        Node*temp=top;
        top=top->next;
        delete temp;
    }
}
void peek()
{
    if(top==NULL)
    {
        cout<<"the stack is underflow"<<endl;
    }
    else
    {
       cout<<top->data;
    }
}

void display()
{
    Node*temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main()
{
    stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.display();
     s.pop();
      s.display();
    s.peek();
   s.display();
}