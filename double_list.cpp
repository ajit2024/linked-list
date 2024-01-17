#include<iostream>
using namespace std;

class node
{
    int data;
    node* link;
    node* prev;
public:

    node(int d):data(d),link(nullptr),prev(nullptr){}
    friend void addnode(int data,node* &head);
    friend void display(node* head);
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

    display(head);
    return 0;
}
