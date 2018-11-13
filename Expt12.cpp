/*Write a menu driven program that implements the following operations on a
Binary search tree : 
•	Insert a new element 
•	Delete an existing element 
•	Traversing the tree o	Pre-order Traversal o	In-order Traversal o	Post-order Traversal*/

#include<iostream>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    int a[20];
    cout<<"Enter size : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    cout<<"Sorted array :\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

