/**
 * Question:
 * You are given a string s of lowercase English letters and an integer array shifts of the same length.
 * Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
 * For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
 * Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
 */

class Solution {
public:
    string shiftingLetters(string s, vector<int>&shifts) {
        for (int i=shifts.size()-1, k=0; i>=0; --i, k%=26)
            s[i] = ((s[i] - 'a') + (k+=shifts[i])) % 26 + 'a';
        return s;
    }
};
