/**
 * Given an array of integers nums and an integer k, 
 * return the number of contiguous subarrays 
 * where the product of all the elements in the subarray is strictly less than k.
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<1) return 0;
        int count=0, prod=1;
        for (int l=0, r=0; r<nums.size(); r++) {
            prod*=nums[r];
            while (l<=r && prod>=k) {
                prod/=nums[l];
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
};
