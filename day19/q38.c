/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2*/
int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int max_sum = nums[0], cur_max = 0;
    int min_sum = nums[0], cur_min = 0;

    for (int i = 0; i < numsSize; i++) {
        cur_max = (cur_max + nums[i] > nums[i]) ? cur_max + nums[i] : nums[i];
        max_sum = (cur_max > max_sum) ? cur_max : max_sum;

        cur_min = (cur_min + nums[i] < nums[i]) ? cur_min + nums[i] : nums[i];
        min_sum = (cur_min < min_sum) ? cur_min : min_sum;

        total += nums[i];
    }

    return max_sum > 0 ? (max_sum > total - min_sum ? max_sum : total - min_sum) : max_sum;
}