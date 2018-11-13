/*Write a menu driven program that implements the following operations on a doubly and Circular linked list : 
•	Insert a new element at the beginning ,end and in-between the given list 
•	Delete an existing element 
•	Search an element 
•	Display all the elements*/

#include <iostream>
using namespace std;

struct node
{   struct node *prev;
    int data;
    struct node *next;
};
struct linked_list
{
    node *head,*tail;
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    node *createnode(int);
    void insert_beg();
    void display();
    void insert_end(int a);
    void insert_after();
    void insert_before();
    void delete_beg();
    void delete_end();
    void delete_after();
    void delete_before();
    void search_element();

};
node *linked_list :: createnode(int x)
{
    node *temp = new node;
    temp->prev=NULL;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

void linked_list :: insert_beg()
{
    int ele;
    node *p,*ptr;
    cout<<"enter element ";
    cin>>ele;
    p=createnode(ele);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
}
void linked_list :: insert_before()
{
    int data2,x;
    node *p,*ptr;
    cout<<"enter element to insert ";
    cin>>data2;
    p=createnode(data2);
    cout<<"enter node to insert before ";
    cin>>x;
    ptr=head;
    while(ptr->data!=x)
    {
        ptr=ptr->next;
    }
    if(ptr->prev==NULL)
    {
        p->next=ptr;
        ptr->prev=p;
        head=p;
    }
    else
    {
    ptr->prev->next=p;
    p->prev=ptr->prev;
    p->next=ptr;
    ptr->prev=p;
    }


}
void linked_list :: insert_after()
{
    int data1,x;
    node *p,*ptr;
    cout<<"Enter element to insert: \n";
    cin>>data1;
    p=createnode(data1);
    cout<<"Enter after which node to insert: \n";
    cin>>x;
    ptr=head;
    while(ptr->data!=x)
    {
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
        ptr->next=p;
        p->prev=ptr;
    }
    else
    {
         p->next=ptr->next;
    ptr->next->prev=p;
    ptr->next=p;
    p->prev=ptr;

    }


}
void linked_list :: insert_end(int a)
{

    node *n,*ptr;
     n=createnode(a);
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
        n->prev=ptr;
    }

}


void linked_list :: display()
{
    tail=head;
    if(head==NULL)
    {
        cout<<"Linked List is Empty.\n";
    }
    while(tail!=NULL)
    {
        cout<<tail->data<<" <-> ";
        tail=tail->next;
    }
    cout<<"NULL\n";
}
void linked_list :: delete_beg()
{
    if(head==NULL)
    {
        cout<<"doubly link list is empty.\n";
    }
    else if(head->next==NULL)
    {
        head=NULL;
        cout<<"No element left in linked list.\n";
    }
    else
    {
    head=head->next;
    head->prev=NULL;
    }

}
void linked_list :: delete_end()
{
    node *ptr;
    ptr=head;
    if(head==NULL)
    {
        cout<<"Doubly link list is empty\n";
    }
    else if(head->next==NULL)
    {
        head=NULL;
        cout<<"No element left in ll\n";
    }
    else
    {
         while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
   ptr->prev->next=NULL;
    }

}
void linked_list :: delete_after()
{   int x;
    node *ptr;
    cout<<"Enter a node element after which to delete.\n";
    cin>>x;
    ptr=head;
    while(ptr->data!=x)
    {
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
        cout<<"After can't be performed\n";
    }
    else if(ptr->next->next==NULL)
    {
        ptr->next=NULL;
    }
    else
    {
        ptr->next=ptr->next->next;
    ptr->next->prev=ptr;
    }

}
void linked_list :: delete_before()
{  int x;
    node *ptr;
    cout<<"Enter a node element before which to delete\n";
    cin>>x;
    ptr=head;
    while(ptr->data!=x)
    {
        ptr=ptr->next;
    }
    if(x==head->data)
    {
        cout<<"Before can't be performed\n";
    }
    else if(ptr->prev->prev==NULL)
    {
        head=ptr;
        head->prev=NULL;
    }
    else{
       ptr->prev=ptr->prev->prev;
    ptr->prev->next=ptr;
    }

}
void linked_list :: search_element()
{
    int ele;
    int flag=0;
    cout<<"enter element to search : ";
    cin>>ele;
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==ele)
        {
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1)
    {
        cout<<"element found in link list\n";
    }
    else
    {
        cout<<"element not found in link list\n";
    }
}
int main()
{
    linked_list l;
    int ch,n,data;
    cout<<"enter size\n";
    cin>>n;
    cout<<"enter elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.insert_end(data);
    }
    cout<<"enter :\n1 to insert at beg\n2 to display\n3 to insert at end\n4 to insert after\n5 to insert before\n6 to delete beg\n7 to delete end\n8 to delete_after\n9 to delete before\n10 search element\n11 exit\n";
    cin>>ch;
    while(ch!=11)
    {
        switch(ch)
        {
            case 1 : l.insert_beg();
            break;
            case 2 : l.display();
            break;
            case 3 :
                {
                    cout<<"enter element : ";
                    cin>>data;
                    l.insert_end(data);
                    break;
                }
            case 4 : l.insert_after();
            break;
            case 5 : l.insert_before();
            break;
            case 6 : l.delete_beg();
            break;
            case 7 : l.delete_end();
            break;
            case 8 : l.delete_after();
            break;
            case 9 : l.delete_before();
            break;
            case 10 : l.search_element();
            break;
        }
    cout<<"enter :\n1 to insert at beg\n2 to display\n3 to insert at end\n4 to insert after\n5 to insert before\n6 to delete beg\n7 to delete end\n8 to delete_after\n9 to delete before\n10 search element\n11 exit\n";
    cin>>ch;
    }
    return 0;
}

