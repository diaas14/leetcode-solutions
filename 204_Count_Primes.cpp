/**
 * Question:
 * Given an integer n, return the number of prime numbers 
 * that are strictly less than n.
 */

class Solution {
public:   
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int count=0;
        for (int i=2; i*i<n; i++) {
            if (isPrime[i]) {
                for (int j=i*i; j<n; j+=i)
                    isPrime[j]=false;
            }
        }
        for (int k=2; k<n; k++) 
            if (isPrime[k]) count++;
        return count;
    }
};
