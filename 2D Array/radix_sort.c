#include<stdio.h>
#include<stdlib.h>
int max(int *,int);
int count(int);
int digit(int,int);
void radix_sort(int *,int);

int main(){
    int *a,n,i;
    printf("Enter how many numbers you want in array: ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    //input array
    for(int i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }

    radix_sort(a,n);

    printf("Array after radix sorting is : \n");
    //output array
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);


    return 0;
}

int max(int *a,int n){
    int m=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>m);
        m=a[i];
    }
    return m;
}

int count(int n){
    int cnt=0;
    while(n){
        n/=10;
        cnt++;
    }
    return cnt;
}

int digit(int n,int k){
 int i,dig;
 for(i=1;i<=k;i++){
    dig=n%10;
    n/=10;
 }
 return dig;
}

void radix_sort(int *a,int n){
 int mat[10][n],i,j,k,l,m,d,r,c;
 m=max(a,n);
 d=count(m);

 for(k=1;k<=d;k++){
  // initialize array with sentinel value -1
    for(i=0;i<10;i++)
    for(j=0;j<n;j++)
    mat[i][j] = -1;

    // copy aray a into matrix mat
    for(i=0;i<n;i++){
        r=digit(a[i],k);
        c=0;
        while(mat[r][c]!=-1)
        c++;
        mat[r][c]=a[i];
    }

    // copy matrix mat to array except sentinel value
    l=0;          // for  a array
    for(i=0;i<10;i++)
        for(j=0;j<n;j++){
            if(mat[i][j]!=-1)
                a[l++]=mat[i][j];

        }
 }
}
