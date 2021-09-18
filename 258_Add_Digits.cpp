/**
 * Question:
 * Given an integer num, repeatedly add all its digits 
 * until the result has only one digit, and return it.
 */

class Solution {
public:
    int addDigits(int num) {
        return (num == 0) ? 0 : (num % 9 == 0) ? 9 : num % 9;
    }
};
