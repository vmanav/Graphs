#include<iostream>
using namespace std;

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
 for(i=1;i<=n;i++)
  if(a[v][i] && !visited[i])
   q[++r]=i;
 if(f<=r)
 {
  visited[q[f]]=1;
  bfs(q[f++]);
 }
}
int main()
{
 int v;

 cout<<"enter the number of vertices:\n";
 cin>>n;cout<<endl;

 for(i=1;i<=n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 cout<<"enter graph data in matrix form :\n";
 for(i=1;i<=n;i++)
 {for(j=1;j<=n;j++)
   cin>>a[i][j];
   }
  
 cout<<endl;  
 cout<<"enter the starting vertex: \n";
 cin>>v;cout<<endl;
 bfs(v);
cout<<"bfs traversal :\n";
 for(i=1;i<=n;i++)
  if(visited[i])
   cout<<i<<"\t";
  else
   cout<<"\n Bfs is not possible\n";
 
}