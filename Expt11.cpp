/*Write a program to accept N numbers from the user in one array and M numbers in another array. 
Then, sort the arrays using Selection Sort and then merge these two arrays using Merge Sort.*/

#include <iostream>

using namespace std;
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
node *createnode(int x)
{
    node *temp=new node;
    temp->left=NULL;
    temp->data=x;
    temp->right=NULL;
    return temp;
}
node *insert_node(node *root,int ele)
{
    node *p;
    p=createnode(ele);
    if(root==NULL)
    {
        root=p;
    }
    else if(p->data<root->data)
    {
        root->left=insert_node(root->left,p->data);

    }
    else
    {
        root->right=insert_node(root->right,p->data);

    }
    return root;
}
node* findmin(node *root)
{
	node *temp=NULL;
	if(root->left!=NULL)
    {
        temp=findmin(root->left);
        return temp;
    }
    else
    {
        return root;
    }
}
node *delete1(node *root,int b)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->data==b)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		else if(root->left==NULL)
		{
			node *temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			node *temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else
		{
			node *temp=findmin(root->right);
			root->data=temp->data;
			root->right=delete1(root->right,temp->data);
		}
	}
	else if(b<root->data)
	{
			root->left=delete1(root->left,b);
	}
	else
	{
			root->right=delete1(root->right,b);
	}
	return root;
}
void inorder(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    inorder(ptr->left);
    cout<<ptr->data<<" ";
    inorder(ptr->right);
}
void preorder(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }

    cout<<ptr->data<<" ";
    preorder(ptr->left);
    preorder(ptr->right);
}
void postorder(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->data<<" ";
}
int main()
{
    int n,ch,item;
    node *root=NULL;
    cout<<"SIZE : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>item;
        root=insert_node(root,item);
    }
    cout<<"\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Delete\n6. Exit\n";
    cin>>ch;
    while(ch!=6)
    {
        switch(ch)
        {
        case 1:
            {
               cin>>item;
               root=insert_node(root,item);
               break;
            }
            case 2 : inorder(root);
            break;
            case 3 : preorder(root);
            break;
            case 4 : postorder(root);
            break;
            case 5 :
                {
                    cout<<"Element to delete : ";
                    cin>>item;
                    delete1(root,item);
                    break;
                }

        }
    cout<<"\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Delete\n6. Exit\n";
    cin>>ch;
    }

    return 0;
}

