/**
 * You are given an integer array nums. 
 * You want to maximize the number of points you get by performing the following operation any number of times:
 * Pick any nums[i] and delete it to earn nums[i] points. 
 * Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
 * Return the maximum number of points you can earn by applying the above operation some number of times. 
 */
 
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        constexpr int n = 10001;
        int val[n]{0};
        int cache[2];
        for (int num : nums)
            val[num] += num;
        cache[0] = val[0];
        cache[1] = max(val[0], val[1]);
        
        for (int i=2; i<n; i++)
            cache[i%2] = max(cache[(i-2)%2]+val[i], cache[(i-1)%2]);
        return cache[(n-1)%2];
    }
};
