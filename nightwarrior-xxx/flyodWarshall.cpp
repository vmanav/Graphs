//flyod warshall algorithm is used to find min distance fron a node to every node
// Whose distance is not given use '999999'
#include<iostream>
using namespace std;
void flyod(int b[][2]){
  for(int k=0;k<2;k++){
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        if(b[i][j]>b[i][k]+b[k][j]){
          b[i][j]=b[i][k]+b[k][j];
        }
      }
    }
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      cout<<b[i][j]<<" ";
    }
    cout<<endl;
  }

}
int main(){
  int b[2][2],i,j;
  for(int i=0;i<2;i++){
    cout<<"Enter the value of "<<i+1<<" row:-";
    for(int j=0;j<2;j++){
      cin>>b[i][j];
    }
  }
  flyod(b);
}


