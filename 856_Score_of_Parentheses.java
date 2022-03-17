/**
 * Given a balanced parentheses string s, return the score of the string.
 * The score of a balanced parentheses string is based on the following rule:
 * "()" has score 1.
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 */ 

class Solution {
    public int scoreOfParentheses(String s) {
        int cur = 0;
        Stack<Integer> scores = new Stack<>();
        for (char c: s.toCharArray()) {
            if (c == '(') {
                scores.push(cur);
                cur = 0;
            } else {
                cur = scores.pop() + Math.max(1, cur*2); 
                // min 1 for the inner most "()"
            } // case c == ')'
        }
        return cur;
    }
}
