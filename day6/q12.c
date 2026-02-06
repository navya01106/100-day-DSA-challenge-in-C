#include<stdio.h>

void moveZeroes(int* nums, int n) 
{
    int left = 0; 
    for(int right = 0; right < n; right++) 
    {
        if(nums[right] != 0) {
            nums[left] = nums[right];
            left++;
        }
    }
    for(int i = left; i < n; i++) 
    {
        nums[i] = 0;
    }
}
int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    moveZeroes(nums, n);
    
    printf("Output: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
