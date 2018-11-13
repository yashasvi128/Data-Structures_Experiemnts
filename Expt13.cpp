//Program including all Operations on Graph and illustrate the traversals using DFS and BFS

#include <iostream>
using namespace std;
int a[20][20], q[20],top=-1,front=-1,rear=-1,vis[20],stack[20];
void create_matrix(int n)
{
    int x,y;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    cout<<"enter two nodes to display edge or -1 to exit:\n";
    cin>>x;
    cin>>y;
    while( x!=-1 && y!=-1)
    {

        a[x][y]=1;
        a[y][x]=1;
        cin>>x;
        cin>>y;
    }
}
void add_edge()
{
    int x;
    int y;
    cout<<"enter two nodes to add edge : ";
    cin>>x;
    cin>>y;
    a[x][y]=1;
    a[y][x]=1;
}
void delete_edge()
{
    int x;
    int y;
    cout<<"enter two nodes to delete edge : ";
    cin>>x;
    cin>>y;
    a[x][y]=0;
    a[y][x]=0;
}
void display(int n)
{
       for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void add(int item)
{
  if(rear==-1)
  {
    q[++rear]=item;
    front++;
  }
  else
   q[++rear]=item;
}
int delete1()
{
    int k;
    if((front>rear)||(front==-1))
      return(0);
    else
    {
       k=q[front++];
       return(k);
    }
}
void bfs(int s,int n)
{
    int p,i;
    add(s);
    vis[s]=1;
    p=delete1();
    if(p!=0)
    cout<<p<<" ";
    while(p!=0)
    {
      for(i=1;i<=n;i++)
         if((a[p][i]!=0)&&(vis[i]==0))
          {
            add(i);
            vis[i]=1;
          }
       p=delete1();
       if(p!=0)
         cout<<p<<" ";
     }
   for(i=1;i<=n;i++)
      if(vis[i]==0)
          bfs(i,n);
}
void push(int item)
{
  stack[++top]=item;
}
int pop()
{
  int k;
  if(top==-1)
  return(0);
  else
  {
    k=stack[top--];
    return(k);
  }
}
void dfs(int s,int n)
{
   int i,k;
   push(s);
   vis[s]=1;
   k=pop();
   if(k!=0)
     cout<<k<<" ";
   while(k!=0)
   {
      for(i=1;i<=n;i++)
         if((a[k][i]!=0)&&(vis[i]==0))
         {
           push(i);
           vis[i]=1;
         }
      k=pop();
      if(k!=0)
        cout<<k<<" ";
   }
   for(i=1;i<=n;i++)
       if(vis[i]==0)
          dfs(i,n);
}
int main()
{
    int ch;
    int n,v,s;
    cout<<"enter no of vertices ";
    cin>>n;
    create_matrix(n);
    cout<<"1 add edge\n2 delete edge\n3 display matrix\n4 dfs traversal\n5 bfs traversal\n6 exit\n";
    cin>>ch;
    while(ch!=6)
    {
        switch(ch)
        {
            case 1 : add_edge();
            break;
            case 2 : delete_edge();
            break;
            case 3: display(n);
            break;
            case 4 :
            {    for(int i=1;i<=n;i++)
                  vis[i]=0;
                 cout<<"enter source vertex : ";
                 cin>>v;
                 dfs(v,n);
                 cout<<endl;
                 break;
           }
            case 5 :
            {
                for(int i=1;i<=n;i++)
                  vis[i]=0;
                cout<<"enter source vertex : ";
                cin>>s;
                bfs(s,n);
                cout<<endl;
                break;
            }
        }
    cout<<"1 add edge\n2 delete edge\n3 display matrix\n4 dfs traversal\n5 bfs traversal\n6 exit\n";
    cin>>ch;
    }
   return 0;
}
