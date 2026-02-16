#include<stdio.h>
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    
    int temp[numsSize];
    
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }
    
    for (int i = 0; i < numsSize; i++) {
        nums[(i + k) % numsSize] = temp[i];
    }
}