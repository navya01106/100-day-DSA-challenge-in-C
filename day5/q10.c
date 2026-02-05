//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

//Merge nums1 and nums2 into a single array sorted in non-decreasing order.

//The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
#include<stdio.h>
int main()
{   int n,m;
    printf("enter length of nums1 ");
    scanf("%d",&n);
printf("enter the length of the nums2");
    scanf("%d",&m);

    int nums1[n+m],nums2[m];
    printf("elements of num1");
    for(int i=0;i<n;i++)
    scanf("%d",&nums1[i]);
printf("elements of num2");
for(int i=0;i<m;i++)
    scanf("%d",&nums2[i]);
int i=n-1;
int j=m-1;
int k=n+m-1;
while(i>=0&&j>=0)
{
    if(nums1[i]>nums2[j])
    {
        nums1[k]=nums1[i];i--;
    }
    else{
        nums1[k]=nums2[j--];
    }
    k--;
}
    while (j >= 0)
     {
        nums1[k--] = nums2[j--];
    }
for(int l = 0; l < (n+m); l++)
        printf("%d ", nums1[l]);
    
    return 0;
}