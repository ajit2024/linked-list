#include<iostream>
#include<vector>
using namespace std;

static int c=1;

class node
{
    int data;
    node* link;

public:
    node(int d):data(d),link(nullptr){}
    friend void addnode(int data,node* &head);
    friend void display(node* head);
    friend void middlenode(node* head);
};

void addnode(int data,node* &head)
{
    static node* temp= head;
    temp->link= new node(data);
    c++;
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
void middlenode(node* head)
{
    //if(c%2==0)
    {
        for(int i=0;i<c/2;i++)
        {
            head=head->link;
        }
        cout<<"the middle element: "<<head->data<<endl;
    }

}
int main()
{
    vector<int>v={10,11,22,33,44,55};
    node* head= new node(v.at(0));

    for(int i=1;i<v.size();i++)
        addnode(v.at(i),head);

    cout<<endl;
    display(head);
    cout<<endl<<c<<endl;
    middlenode(head);
    return 0;
}
