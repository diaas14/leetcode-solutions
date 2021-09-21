/**
 * Question:
 * Given an integer array nums, move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 */

Note that you must do this in-place without making a copy of the array.class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z_count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0)
                z_count += 1;
            else {
                if (z_count > 0) {
                    nums[i - z_count] = nums[i];
                nums[i] = 0;
                }
            }
        }
    }
};
