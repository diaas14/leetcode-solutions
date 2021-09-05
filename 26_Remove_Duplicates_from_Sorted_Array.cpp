/**
 * Question:
 * Given an integer array nums sorted in non-decreasing order, 
 * remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0;
        for (int i=1; i<nums.size(); i++) {
            if(nums[i]==nums[i-1]) dup++;
            else nums[i-dup]=nums[i];           
        }
        return nums.size()-dup;
    }
};
