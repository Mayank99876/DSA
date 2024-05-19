#include<stdio.h>
#include<stdlib.h>

int main(){
    int **m,r,c,i,j;
    printf("Enter how many rows and columns : ");
    scanf("%d%d",&r,&c);
    m=(int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        m[i] = (int *)malloc(c*sizeof(int));
    }

    //input
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter element:");
            scanf("%d",&m[i][j]);
        }
    }
// output
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
//free

   for(i=0;i<r;i++)
      free(m[i]);
      m=NULL;

    return 0;
}