/**
 * Question:
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 * For example, "ACGAATTCCG" is a DNA sequence.
 * When studying DNA, it is useful to identify repeated sequences within the DNA.
 * Given a string s that represents a DNA sequence, 
 * return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
 * You may return the answer in any order.
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> check;
        vector<string> res;
        if (s.size() < 10) return res; 
        for (int i=0; i<s.size()-10+1; i++) {
            if (check.find(s.substr(i, 10)) == check.end())
                check[s.substr(i, 10)] = 1;
            else 
                check[s.substr(i, 10)]++;
        }
        for (auto p: check) {
            if (p.second > 1) 
                res.push_back(p.first);
        }
        return res;
    }
};
