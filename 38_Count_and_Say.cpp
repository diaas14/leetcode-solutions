/**
 * Question:
 * The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
 *   countAndSay(1) = "1"
 *   countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
 *   which is then converted into a different digit string.
 * To determine how you "say" a digit string, split it into the minimal number of groups 
 * so that each group is a contiguous section all of the same character. 
 * Then for each group, say the number of characters, then say the character. 
 * To convert the saying into a digit string, replace the counts 
 * with a number and concatenate every saying.
 */


class Solution {
public:
    /*
        1 -> 1
        2 -> 11
        3 -> 21
        4 -> 1211
    */
    string countAndSay(int n) {
        // base case
        if (n == 1) return "1";
        // recursion
        int i=0, count=0;
        string prev = countAndSay(n-1);
        stringstream ss;
        while (i<prev.size()) {
            count=1;
            while (i+1<prev.size() && prev[i] == prev[i+1]) {
                count++;
                i++;
            }
            ss << count << prev[i];
            i++;
        }
        return ss.str();
    }
};
