// flyod for detecting negative cycles
// use 99999n= whose weight is not none
#include<iostream>
using namespace std;
#define n 4
bool detector(int b[][n]){
  int d[n][n],i,j,k; // where d[][] is the distance array
  //Filling the d[][] array 
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      d[i][j]=b[i][j];
    }
  }
  for(k=0;k<n;k++){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(d[i][j]>d[i][k]+d[k][j]){
          d[i][j]=d[i][k]+d[k][j];
        }
      }
    }
  }
  for(i=0;i<n;i++){
    if(d[i][i]<0){
      return true;
    }
  }
  return false;

}
int main(){
  int b[n][n],i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin>>b[i][j];
    }
  }
  if(detector(b)){
    cout<<"Yes";
  }
  else{
    cout<<"False";
  }
}
