/**
 * Question:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 */

class Solution {
public:
    static bool validPair(char top, char c) {
        return ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) ? true: false;
    }
    
    bool isValid(string s) {
        stack<char> symbols;
        for (char &c: s) {
            if (c == '(' || c == '[' || c == '{') symbols.push(c);
            else {
                if (symbols.empty() || !validPair(symbols.top(), c))
                    return false;
                symbols.pop();
            }
        }
        return symbols.empty() ? true: false;
    }
};
