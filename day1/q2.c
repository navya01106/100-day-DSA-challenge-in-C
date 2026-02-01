/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include<stdio.h>
int main()
{
    int n,target;
    printf("enter the length of the array");
    scanf("%d",&n);
    int nums[n];
    printf("enter the elements of the array");
    for(int i=0;i<n;i++)
    scanf("%d",&nums[i]);

    printf("enter the target element");
    scanf("%d",&target);
   
for(int i=1;i<n;i++)
{for(int j=1;j<n;j++){
 if(nums[j]+nums[i]==target)
 printf("[%d,%d]\n",nums[i],nums[j]);
}}
return 0;
}

