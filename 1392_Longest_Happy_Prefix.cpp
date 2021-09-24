/**
 * Question:
 * A string is called a happy prefix if is a non-empty prefix 
 * which is also a suffix (excluding itself).
 * Given a string s, return the longest happy prefix of s. 
 * Return an empty string "" if no such prefix exists.
 */

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        int i=1, j=0;
        while(i < s.size()) {
            if (s[i] == s[j]) {
                lps[i] = j+1;
                i++; j++;
            }    
            else {
                if (j == 0) lps[i++] = 0;
                else j = lps[j - 1];
            }
        }
        return s.substr(0, lps[i-1]);        
    }
};
