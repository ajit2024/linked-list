#include<iostream>
using namespace std;

class node
{
    int data;
    node* link;
public:
    node(int d):data(d),link(nullptr){}
    friend void addnode(int data,node* &head);
    friend void display(node* head);
    friend void reverse_list(node* &head);
};

void addnode(int data,node* &head)
{
    static node*temp=head;
    temp->link= new node(data);
    temp=temp->link;
}

void display(node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<"-->";
        head=head->link;
    }
    cout<<"null"<<endl;
}

void reverse_list(node* &head)
{
    node* curr= head;
    node* prev= nullptr;
    node* next= nullptr;

    while(curr!=nullptr)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    prev=nullptr;
}

int main()
{
    node* head= new node(5);
    addnode(6,head);
    addnode(7,head);
    addnode(8,head);

    cout<<endl<<"original linked-list"<<endl;
    display(head);// original list

    cout<<endl<<"reverse of linked-list"<<endl;
    reverse_list(head);
    display(head);// reverse list

    return 0;
}
