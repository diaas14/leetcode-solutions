/**
 * Question: 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 */

class Solution {

public:
    // two pointer approach without using extra space
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i, j, k;
        for (i = 0; i < nums.size(); i++) {
            // to avoid duplicates
            if (i != 0 && nums[i] == nums[i-1]) continue;
            // two pointers
            // j - left pointer
            // k - right pointer
            j = i + 1;
            k = nums.size() - 1;
            
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    j++;
                    // to avoid duplicates
                    while (j < k && nums[j] == nums[j-1]) j++;
                }
                else if (nums[j] + nums[k] < -nums[i]) j++;
                else k--;
            }
        }
        return res;
    }
};
