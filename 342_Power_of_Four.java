/**
 * Given an integer n, return true if it is a power of four. Otherwise, return false.
 * An integer n is a power of four, if there exists an integer x such that n == 4x.
 */

class Solution {
    public boolean isPowerOfFour(int n) {
        return (n == 1 || (n&(n-1)) == 0 && (n-1)%3 == 0);
    }
}
