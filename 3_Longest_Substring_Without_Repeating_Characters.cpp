/**
 * Question:
 * Given a string s, 
 * find the length of the longest substring without repeating characters.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int l=0, r=0;
        unordered_set<char> check;
        while(r<s.size()) {
            if(check.find(s[r]) == check.end()) {
                res=max(res, r-l+1);
                check.insert(s[r]);
                r++;
            } else {
                check.erase(s[l]);
                l++;
            }
        } 
        return res;
    }
};
