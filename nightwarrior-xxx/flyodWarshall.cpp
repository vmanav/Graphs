#include <iostream>
#include<limits.h>
using namespace std;
void flyod(int b[][3]){
    int k,i,j;
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(b[i][j]>b[i][k]+b[k][j]){
                    b[i][j]=b[i][k]+b[k][j];
                }
            }
        }
    }
}
int main(){
 int b[3][3],i,j,k;
  for(i=0;i<3;i++){
     cout<<"Enter the row " <<i+1<<" elements:-";
     for(j=0;j<3;j++){
         cin>>b[i][j];
     }
 }
 flyod(b);
   for(i=0;i<3;i++){
     for(j=0;j<3;j++){
         cout<<b[i][j]<<" ";
     }
     cout<<endl;
}
}
