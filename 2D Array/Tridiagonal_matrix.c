#include<stdio.h>
#include<stdlib.h>
# define ROW 10
# define COL 10
void input(int [][COL],int,int);
int check_tridiagonal(int [][COL],int,int);
int main(){
 int i,j,r,c;
 int m[ROW][COL];
 printf("Enter how many rows and columns you want: ");
 scanf("%d%d",&r,&c);
 input(m,r,c);
 if(check_tridiagonal(m,r,c)){
    printf("Yes it is a tridiagonal matrix");
 }
 else{
    printf("No it is not a tridiagonal matrix");
 }
 return 0;
}

void input(int m[][COL],int r,int c){
 int i,j;
 for(i=0;i<r;i++){
    for(j=0;j<c;j++){
            printf("Enter element %d,%d: ",i+1,j+1);
            scanf("%d",&m[i][j]);
     }
  }
}

int check_tridiagonal(int m[][COL],int r,int c){
  int i,j;
  if(r!=c){
      return 0;
        }
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        if(abs(i-j)>1 && m[i][j]!=0){
            return 0;
        }
    }
  }
  return 1;
}
