//Write a program to accept N numbers from the user and store them in an array. Then, accept another number from the user and search that using Linear Search.

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

    cout<<"Enter element to search : \n";
    cin>>ele;
    int pos = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]== ele)
        {
            pos=i;
            break;
        }
    }

    if(pos==-1)
    {
        cout<<"Element Not Found ";
    }
    else
    {
        cout<<"Element "<<ele<<" is at "<<pos+1<<" position";
    }
    return 0;
}
