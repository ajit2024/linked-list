#include<iostream>
#include<algorithm>
using namespace std;


class node  // creation of node
{
    int data;
    node* link;
    node* prev;
public:

    node(int d):data(d),link(nullptr),prev(nullptr){}
    friend void addnode(int data,node* &head);
    friend void display(node* head);
    friend void reverselist(node* &head);
};

void addnode(int data,node* &head)
{
    static node* temp= head;
    static node* t= head;
    temp->link= new node(data);
    temp= temp->link;
    temp->prev= t;
    t= temp;
}

void reverselist(node* &head)
{
    node* temp= head;
    do
    {
        swap(temp->link,temp->prev);
        if(temp->prev==nullptr)
            head=temp;

        temp= temp->prev;
    }while(temp!= nullptr);
}

void display(node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" <---> ";
        head=head->link;
    }
    cout<<"null"<<endl;
}

int main()
{
    node* head= new node(3);
    cout<<endl;

    addnode(4,head);
    addnode(5,head);
    addnode(6,head);
    cout<<" the original double linked-list "<<endl;
    display(head);  // displaying the original list

    cout<<endl<<" the reverse of double linked-list "<<endl;
    reverselist(head);
    display(head);  // displaying the reverse list

    return 0;
}

