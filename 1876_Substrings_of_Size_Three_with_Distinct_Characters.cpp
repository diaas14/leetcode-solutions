/**
 * Question:
 * A string is good if there are no repeated characters.
 * Given a string s, return the number of good substrings of length three in s.
 * Note that if there are multiple occurrences of the same substring, 
 * every occurrence should be counted.
 * A substring is a contiguous sequence of characters in a string
 */

class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3, count = 0;
        if (s.length() < 3) return count;
        int check[26]{}, i = 0, j = 0;
        while (i < s.length() - k + 1) {
            if (!check[s[j] - 'a']) {
                // check if the length of the window is equal to k
                if (j - i == k - 1) { 
                    count ++;
                    // moving the left side of the window one step right
                    // we will also move the right side of the window
                    check[s[i] - 'a'] = 0;
                    i ++;
                }
                // moving the right side of the window one step right
                check[s[j] - 'a'] = 1;
                j++;
            } else {
                // if repeated characters found,
                // keep shrinking the left side of the window until 
                // we have unique characters again
                check[s[i] - 'a'] = 0;
                i++;
            }
        }
        return count;
    }
};
