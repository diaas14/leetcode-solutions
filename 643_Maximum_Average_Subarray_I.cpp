/**
 * Question:
 * You are given an integer array nums consisting of n elements, and an integer k.
 * Find a contiguous subarray whose length is equal to k 
 * that has the maximum average value and return this value. 
 * Any answer with a calculation error less than 10-5 will be accepted.
 */


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=numeric_limits<double>::lowest(), sum=0;
        for (int l=0, r=0; r<nums.size(); r++) {
            sum+=nums[r];
            if (r-l+1<k) continue;
            avg = max(sum/k, avg);
            sum-= nums[l];
            l++;
        }
        return avg;
    }
};
