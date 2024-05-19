#include<iostream>
using namespace std;
int main()
{
 int n,q;
 cin>>n>>q;
 int mat[q][3];
 int** arr = new int*[n];
 int lastanswer=0;
 for(int i=0;i<q;i++){
    for(int j=0;j<3;j++){
        cin>>mat[i][j];
    }
 }

 for(int i=0;i<q;i++){
        if(mat[i][0]==1){
          (mat[i][1]^lastanswer)%n;
    }
 }

 delete[] arr;
  return 0;
}