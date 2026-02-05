/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70*/

#include<stdio.h>
int main()
{   int n1,n2;
    printf("enter the length of the 1st array");
    scanf("%d",&n1);
    int arr1[n1];
    printf("enter the elements of the array");
    for(int i=0;i<n1;i++)
    scanf("%d",&arr1[i]);
printf("enter the length of the 2nd array");
    scanf("%d",&n2);
    int arr2[n2];
    int merge[(n1+n2)];
    printf("enter the elements of the array");
    for(int i=0;i<n2;i++)
    scanf("%d",&arr2[i]);
     int i=0;
     int j=0;
     int k=0;
     while(i<n1&&j<n2)
     {
        if(arr1[i]<=arr2[j])
        {
          merge[k++]=arr1[i++];
        }
        else{
            merge[k++]=arr2[j++];
        }
     }
     while (i < n1) {
        merge[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        merge[k] = arr2[j];
        j++;
        k++;
    }
     for(int l=0;l<(n1+n2);l++)
     printf("%d ,",merge[l]);
    return 0;

}
