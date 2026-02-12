/*Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.*/
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int arr1[m][n],arr2[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&arr1[i][j]);
for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&arr2[i][j]);

    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
     arr1[i][j]+=arr2[i][j];

     for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
     printf("%d ",arr1[i][j]);
    printf("\n");
}
    return 0;

}