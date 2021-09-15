/**
 * Question:
 * Given an integer array nums, 
 * find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 * A subarray is a contiguous part of an array.
 */
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum=INT_MIN, temp_max=0;
        for (auto num: nums) {
            temp_max += num;
            maximum = max(temp_max, maximum);
            if (temp_max < 0)
                temp_max = 0;
        }
        return maximum;
    }
};
