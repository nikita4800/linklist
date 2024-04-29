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
        next=NULL;
    }
};
class queue
{
    Node*front;
    Node*rear;
    public:
    queue()
    {
        front=NULL;
        rear=NULL;
    }
    void push(int data)
    {
        Node*n=new Node(data);
        if(front==NULL)
        {
            rear=n;
            front=n;
            return;
        }
        rear->next=n;
        rear=n;
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"link list is empty cannot delete"<<endl;
            return ;
        }
        Node*n=front;
        front=front->next;
        free(n);
    }
    void display()
    {
        Node*temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void peek()
    {
        if(front==NULL)
        {
            cout<<"the link list is empty"<<endl;
            return;
        }
       cout<<front->data;
    }
    void isempty()
    {
        if(front==NULL)
        {
            cout<<"the linklist is empty"<<endl;
        }
         cout<<"the linklist is nooottt empty"<<endl;
    }
};

int main()
{
    queue q;
    q.push(1);
     q.push(2);
      q.push(3);
       q.push(4);
       q.display();
       q.pop();
       q.display();
       q.peek();
       cout<<endl;
     q.display();

}