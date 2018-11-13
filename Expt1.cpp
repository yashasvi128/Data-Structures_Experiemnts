/*Write a menu driven program that implements following operations on a linear array: 
•	Insert a new element at a specified position 
•	Delete an element either whose value is given or whose position is given 
•	To find the location of a given element 
•	To display the elements of the linear array*/

#include<iostream>

using namespace std;

void insert_ele( int *arr,int &n)
{   int pos,data;
    cout<<"Enter the specific position:"<<endl;
    cin>>pos;
    cout<<"Enter Element:"<<endl;
    cin>>data;
    for(int i=n-1;i>=pos;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = data;
    n = n+1;
}
void delete_ele_value(int *arr,int &n)
{
  int data,index;

  cout<<"Enter element to be deleted"<<endl;
  cin>> data;
  for(int i = 0;i<n;i++)
   {
     if(data == arr[i])
        {
           index = i;
           break;
        }
   }

   for(int i = index ;i<n;i++)
   {
       arr[i]= arr[i+1];
   }
   n--;

}

void delete_ele_pos(int *arr,int &n)
{
    int index;
   cout<<"Enter position of element to be deleted"<<endl;
   cin>> index;
   for(int i = index ;i<n;i++)
   {
       arr[i]= arr[i+1];
   }
   n--;

}


void find_loc(int *arr,int &n)
{
    int ele,i=0;
    cout<<"Enter element:\n";
    cin>>ele;
    while(arr[i]!= ele && i<n)
    {
       i++;
    }
    if(ele==arr[i])
        cout<<"Location: "<<i<<endl;
    else
        cout<<"Element not found\n";

}

void display(int *arr,int &n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int n;
    cout<<"Enter number of elements in an array:"<<endl;
    cin>>n;
    int arr[100];
    cout<<"Enter Array Elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int choice = 0;

    do
    {
        cout<<"1.Insert a new element at a specified position."<<endl;
        cout<<"2.Delete an element from value."<<endl;
        cout<<"3.Delete an element from position."<<endl;
        cout<<"4.Find the location of a given element."<<endl;
        cout<<"5.Display the elements of the linear array."<<endl;
        cout<<"6.Exit\n";

        cin >> choice;

        switch(choice)
        {
        case 1 : insert_ele(arr,n);
                 break;
        case 2 : delete_ele_value(arr,n);
                 break;
        case 3 : delete_ele_pos(arr,n);
                 break;
        case 4 : find_loc(arr,n);
                 break;
        case 5 : display(arr,n);
                 break;
        case 6 : break;
        default : cout<<"Wrong Input"<<endl;
        }

    }while(choice != 6);


    return 0;
}
