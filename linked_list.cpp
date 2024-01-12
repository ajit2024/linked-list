#include<bits/stdc++.h>
using namespace std;

class node
{
private:
    int data;
    node *link;
public:
    node():data(0),link(nullptr){}
    node(int d):data(d),link(nullptr){}
    ~node()
    {
        cout<<" now the distructor run"<<endl;
    }
    void AddNode(int data,node* &head);
    void insertlast(int data,node* &head);
    void Display(node* head);

};
void node::AddNode(int data,node* &head)
{
    node* temp= new node(data);
    temp->link= head;
    head= temp;
    temp=nullptr;
}
void node::insertlast(int data,node* &head)
{
    static node* temp= head;
    temp->link= new node(data);
    temp=temp->link;
}

void node::Display(node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<"-->";
        head=head->link;
    }
    cout<<"null"<<endl;
}

int main()
{
    node* head = new node(3);
    head->insertlast(5,head);
    head->insertlast(4,head);
    head->insertlast(9,head);
    head->AddNode(11,head);
    head->AddNode(12,head);
    head->Display(head);
    return 0;
}

