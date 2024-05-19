#include<stdio.h>
#define MAX 20
void readsparse(int [][3]);
void transpose(int [][3],int [][3]);
void printsparse(int [][3]);

int main(){
    int m1[MAX][3],m2[MAX][3];
    readsparse(m1);
    transpose(m1,m2);
    printsparse(m2);

return 0;
}

void readsparse(int m[][3]){
  int i,n,r,c;
  printf("Enter the size of matrix (rows,columns):");
  scanf("%d%d",&r,&c);
  m[0][0] = r;
  m[0][1] = c;
  printf("\nEnter no. of non-zero element: ");
  scanf("%d",&n);
  m[0][2]=n;

   for(int i=1;i<=n;i++){
    printf("\nEnter the next triple(row,column,value): ");
    scanf("%d%d%d",&m[i][0],&m[i][1],&m[i][2]);

   }
}

void transpose(int sm1[][3],int sm2[][3]){
    int i,j,n,col;

    sm2[0][0] = sm1[0][1];
    sm2[0][1] = sm1[0][0];
    sm2[0][2] = sm1[0][2];

    j=1;
    n=sm1[0][2];
    if(n>0){
        for(col=0;col<sm1[0][1];col++)
         for(i=1;i<=n;i++)
          if(col=sm1[i][1]){
            sm2[j][0] = sm1[i][1];
            sm2[j][1] = sm1[i][0];
            sm2[j][2] =sm2[i][2];
            j++;
          }
    }
}

void printsparse(int m[][3]){
    int i,n;
    n=m[0][2];
    printf("\nrow\t\tcolumn\t\tvalue\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",m[i][0],m[i][1],m[i][2]);
    }
}