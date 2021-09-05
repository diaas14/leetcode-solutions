/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stringstream ss;
        int i{}, j{};
        for (i=0; i<strs[0].length(); i++) {
            for (j=1; j<strs.size() && i < strs[j].size(); j++) {
                if (strs[j][i] != strs[0][i]) break;
            }
            if (j == strs.size()) ss << strs[0][i];
            else break;
        }
        return ss.str();
    }
};
