/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
 * such that each number is the sum of the two preceding ones, starting from 0 and 1
 */

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        
        int cache[2];
        cache[0] = 0;
        cache[1] = 1;   
        
        for (int i=2; i<n; i++)
            cache[i%2] = cache[0] + cache[1];
        
        return cache[0] + cache[1];
    }
};
