/**
 * The Tribonacci sequence Tn is defined as follows: 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * Given n, return the value of Tn.
 */

class Solution {
public:
    int tribonacci(int n) {
        int cache[3] = {0, 1, 1};
        for (int i=3; i<=n; i++)
            cache[i%3] = cache[0] + cache[1] + cache[2];
        
        return cache[n%3];
    }
};
