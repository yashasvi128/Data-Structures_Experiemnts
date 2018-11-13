//Write a program to accept N numbers in an array, and then sort the array using Quick Sort.

#include <iostream>

using namespace std;
void selection_sort(int c[],int s)
{
    int min,pos;
    for(int i=0;i<s-1;i++)
    {
        min=i;
        for(int j=i+1;j<s;j++)
        {
            if(c[j]<c[min])
            {
                min=j;
            }
        }
        int temp=c[min];
        c[min]=c[i];
        c[i]=temp;
    }
}
void merge_arrays(int a[],int b[],int n,int m,int a2[])
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            a2[k]=a[i];
            i++;
            k++;
        }
        else
        {
            a2[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        a2[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        a2[k]=b[j];
        j++;
        k++;
    }
}
int main()
{
    int n,m;
    int a[20],b[20];
    cout<<"Enter size of first array: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter size of second array: ";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    selection_sort(a,n);
    selection_sort(b,m);
    int a2[n+m];
    merge_arrays(a,b,n,m,a2);
    cout<<"Sorted merge array :\n";
    for(int i=0;i<n+m;i++)
    {
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    return 0;
}
