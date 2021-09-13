/**
 * You are given an integer array nums. 
 * You are initially positioned at the array's first index, 
 * and each element in the array represents your maximum jump length at that position.
 * Return true if you can reach the last index, or false otherwise.
 */

class Solution {
public:
    /**
     * bool canJump(vector<int>& nums) {
     *   if (nums.size() == 1) return true;
     *   queue<int> bfs;
     *   bfs.push(0);
     *   int pos;
     *   while (!bfs.empty()) {
     *       pos = bfs.front();
     *       bfs.pop();
     *       for (int i=1; i<=nums[pos] && pos+i<nums.size(); i++) {
     *           if (pos + i == nums.size() - 1)
     *               return true;
     *           bfs.push(pos+i);
     *       }    
     *   }
     *   return false;
     * }
     */
    bool canJump(vector<int>& nums) {
        int reach=0, i{};
        for (i=0; i<nums.size() && reach>=i; i++) {
            reach = max(reach, nums[i]+i);
        }
        return i==nums.size();
    }
};
