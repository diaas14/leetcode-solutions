/**
 * You are given an array nums of non-negative integers. 
 * nums is considered special if there exists a number x 
 * such that there are exactly x numbers in nums that are greater than or equal to x.
 * Notice that x does not have to be an element in nums.
 * Return x if the array is special, otherwise, return -1. 
 * It can be proven that if nums is special, the value for x is unique.
 */
 
 class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        // pos refers to the index of the element in the sorted array
        // that are just greater than or equal to previous i
        int pos = 0;
        for (int i=1; i<=nums.length - pos; i++) {
            while (pos < nums.length && nums[pos] < i) pos++;
            if (pos >= nums.length) 
                break;
            if (nums.length - pos == i) 
                return i;
        }
        return -1;
    }
}
