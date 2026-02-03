/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.
Examples:
Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.
 solve this in c without using comments and unnecessary print statements and also keep the variable names short and the code easy*/
#include <stdio.h>

int findMissing(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum = sum+arr[i];
    }
    int total = (n * (n + 1)) / 2;
    return total - sum;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int arr[n - 1];
    printf("Enter %d elements: ", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", findMissing(arr, n));
    
    return 0;
}