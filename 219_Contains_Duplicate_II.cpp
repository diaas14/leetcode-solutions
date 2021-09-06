/**
 * Given an integer array nums and an integer k, 
 * return true if there are two distinct indices i and j in the array 
 * such that nums[i] == nums[j] and abs(i - j) <= k.
 */
 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered set stores latest k elements
        unordered_set<int> ele;
        for (int i=0; i<nums.size(); i++) {
            if (i > k) 
                // removes outdated elements
                ele.erase(nums[i-k-1]);
            if (!ele.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};
