/**
 * Question:
 * Given a string s, reverse the order of characters in each word 
 * within a sentence while still preserving whitespace and initial word order.
 */

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(i<s.size()) {
            int left = i, right{};
            while(i<s.size() && s[i] != ' ') 
                i++;
            right = i - 1;
            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                
                left++;
                right--;
            } 
            i++;
        }
        return s;
    }
};
                  
