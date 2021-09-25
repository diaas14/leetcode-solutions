/**
 * Question:
 * Given an array of strings queries and a string pattern, 
 * return a boolean array answer where answer[i] is true if queries[i] matches pattern, 
 * and false otherwise.
 * A query word queries[i] matches pattern if you can insert 
 * lowercase English letters pattern so that it equals the query. 
 * You may insert each character at any position and you may not insert any characters.
 */

class Solution {
public:
    
    bool isMatch(string query, string pattern) {
        int i = 0;
        for (auto ch: query) {
            if (ch == pattern[i])
                i++;
            else if (ch >= 'A' && ch <= 'Z')
                return false;
        }
       return (i == pattern.size()) ? true : false;
    }
        
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto query: queries) {
            res.push_back(isMatch(query, pattern));
        }
        return res;
    }
};
