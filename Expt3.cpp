/*Write a program to accept N integers from the user and store them in an array. Sort the array in ascending order using Bubble sort.
Then accept another number from the user, search whether that number exists in the array using Binary Search. 
If it does, display its index and if it doesn’t, then print that the number is not found in the array.*/

#include <iostream>
using namespace std;

int main()
{
    int n,ele;

    cout<<"Enter size of array: \n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"Sorted Array: \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter element to search: \n";
    cin>>ele;

    int beg,end,mid,pos = -1;
    beg=0;
    end=n-1;

    mid=(beg+end)/2;
    while(beg<=end)
    {
        if(arr[mid]==ele)
        {
            pos=mid;
            break;
        }
        else if(arr[mid]<ele)
        {
            beg=mid+1;
        }
        else if(arr[mid]>ele)
        {
            end=mid-1;
        }
        mid=(beg+end)/2;
    }

    if(pos==-1)
    {
        cout<<"Element not found \n";
    }
    else
    {
        cout<<"Element "<<ele<<" is at "<<pos+1<<" position\n";
    }

    return 0;
}

