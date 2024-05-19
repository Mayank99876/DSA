#include<stdio.h>
#include<stdlib.h>
void complete_sort(int **,int,int);
int main(){
    int **m,r,c,i,j;
    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    m=(int *)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        m[i]=(int *)malloc(c*sizeof(int));
    }

    //input
    for(int i=0;i<r;i++){ 
       
    }
}

void complete_sort(int **m,int r,int c){
    int i,j,k,l;
    //sort
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
          for(k=j==c-1?i+1:i;k<r;k++)
            for(l=k==i?j+1:0;l<c;l++){
                if(m[i][j]>m[k][l]){
                    int t=m[i][j];
                    m[i][j]=m[k][l];
                    m[k][l]=t;
                }
            }
    }
}