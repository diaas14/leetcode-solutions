/**
 * Question:
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
 * Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 */

class Solution {
public:
    // bottom up approach
    int minCostClimbingStairs(vector<int>& cost) {
        int cache[2] = {cost[0], cost[1]}, len=cost.size();
        for (int i=2; i<len; i++) 
            cache[i%2] = min(cache[0], cache[1]) + cost[i];
        return min(cache[0], cache[1]);
    }
};
