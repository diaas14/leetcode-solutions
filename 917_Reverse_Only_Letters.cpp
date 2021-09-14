/**
 * Question:
 * Given a string s, reverse the string according to the following rules:
 * All the characters that are not English letters remain in the same position.
 * All the English letters (lowercase or uppercase) should be reversed.
 * Return s after reversing it.
 */

class Solution {
public:  
    /**
     * string reverseOnlyLetters(string s) {
     *     vector<int> positions;
     *     for (int i=0; i<s.length(); i++) 
     *         if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') 
     *             positions.push_back(i);
     *     for (int i=0; i<positions.size()/2; i++) 
     *         swap(s[positions[i]], s[positions[positions.size()-1-i]]);
     *     return s;
     * }
     */
    
    string reverseOnlyLetters(string s) {
        stringstream ss;
        int j=s.length()-1;
        for (int i=0; i<s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                while (!(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) 
                    j--;
                ss << s[j--];
            } else
                ss << s[i];
        }
        return ss.str();
    }
};
