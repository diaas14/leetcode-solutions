/**
 * Question:
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 */
 
class Solution {
public:
  
/**
 * int climbStairsRecursive(int n, vector<int>& cache) {
 *    if (n < 0) return 0;
 *   if (n == 0) return 1;
 *    if (cache[n] > 0) return cache[n];    
 *    return climbStairsRecursive(n - 1, cache) + climbStairsRecursive(n - 2, cache);
 * }
 *  
 * int climbStairs(int n) {
 *    vector<int> cache(n + 1, -1);
 *    // cache[0] holds no meaning
 *    return climbStairsRecursive(n, cache);
 * }
 */
    
    int climbStairs(int n) {
        int cache[2];
        cache[0] = 1; // 0 is not a valid input
        cache[1] = 1;
        for (int i=2; i<=n; i++)
            cache[i%2] = cache[0] + cache[1];
        return cache[n%2];
    }
};
