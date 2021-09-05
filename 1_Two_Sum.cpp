/**
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * You can return the answer in any order.
 */
 
 
class Solution {
public:
    // one pass solution using extra space
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> diff;
        for (int i=0; i<nums.size(); i++) {
            if (diff.find(nums[i]) == diff.end()) 
                diff[target-nums[i]] = i;
            else return vector<int>({diff[nums[i]], i});
        }
        return vector<int>();
    }
};
