/**
 * Question:
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, 
 * the only constraint stopping you from robbing each of them is 
 * that adjacent houses have security systems connected 
 * and it will automatically contact the police 
 * if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, 
 * return the maximum amount of money you can rob tonight without alerting the police.
 */
 
class Solution {
public:
    // bottom up iterative approach
    int rob(vector<int>& nums) {
        int cache[2];
        cache[0] = nums[0];
        for (int i=1; i<nums.size(); i++) 
            if (i-2 < 0) 
                cache[i%2] = max(cache[i-1], nums[1]);
            else
                cache[i%2] = max(cache[(i-1)%2], cache[(i-2)%2]+nums[i]);
        return cache[(nums.size()-1)%2];
    }
};
