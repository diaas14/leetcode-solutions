/** 
 * Question:
 * Given an array of non-negative integers nums, 
 * you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 */

class Solution {
public:
    // bfs approach
    int jump(vector<int>& nums) {
        int jumps=0, farthest=0, end=0;
        for (int i=0; i<nums.size() && end<nums.size()-1; i++) {
            farthest = max(farthest, nums[i]+i);
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;   
    }
};
