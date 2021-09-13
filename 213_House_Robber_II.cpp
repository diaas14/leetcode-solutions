/**
 * Question:
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed. 
 * All houses at this place are arranged in a circle. 
 * That means the first house is the neighbor of the last one. 
 * Meanwhile, adjacent houses have a security system connected, 
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, 
 * return the maximum amount of money you can rob tonight without alerting the police.
 */
 
class Solution {
public:
    
    int robUtil(vector<int>& nums, int s, int e) {
        int cache[2];
        cache[s%2] = nums[s];
        for (int i=s+1; i<=e; i++) 
            if (i-2 < s) 
                cache[i%2] = max(cache[(i-1)%2], nums[i]);
            else
                cache[i%2] = max(cache[(i-1)%2], cache[(i-2)%2]+nums[i]);
        return cache[e%2];
    }
    
    /**
     * Since House[1] and House[n] are adjacent, they cannot be robbed together. 
     * Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
     * depending on which choice offers more money. 
     * Now the problem has degenerated to the House Robber, which is already been solved.
     * Refer this: https://github.com/diaas14/leetcode-solutions/blob/19cc501cd7a9fb3c39293082c04458d5a7ee1f47/198_House_Robber.cpp
     */
  
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robUtil(nums, 0, nums.size()-2), robUtil(nums, 1, nums.size()-1));
    }
};
