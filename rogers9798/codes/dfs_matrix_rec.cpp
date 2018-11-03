
#include<iostream>
using namespace std; 
void DFS(int);
int G[10][10],visited[10],n;    
 
 
int main()
{
    int i,j;
cout<<"enter number of vertices :\n";
   
    cin>>n;
 
    cout<<"\nenter adjecency matrix :\n";
   
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            cin>>G[i][j];
 
   
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
}
 
void DFS(int i)
{
    int j;
    cout<<endl;
    cout<<i;
    visited[i]=1;
    
    for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}