/**
 * Question:
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return true if n is an ugly number.
 */

class Solution {
public:
    bool isUgly(int n) {
        if (n < 1)
            return false;
        while (n && n % 3 == 0) n /= 3;
        while (n && n % 2 == 0) n /= 2; 
        while (n && n % 5 == 0) n /= 5;
        return (n == 1);
    }
};
