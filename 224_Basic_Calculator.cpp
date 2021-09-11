/**
 * Given a string s representing a valid expression, 
 * implement a basic calculator to evaluate it
 * and return the result of the evaluation.
 * Note: You are not allowed to use any built-in function 
 * which evaluates strings as mathematical expressions, such as eval().
 */

class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, i=0, num=0;;
        int res1{}, sign1{};
        char c;
        stack<int> store;
        while (i < s.length()) {
            c = s[i];
            if (c >= '0' && c <= '9'){
                num = 0;
                // checking for continguous digits
                while (i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                res = res + sign * num;
                continue;
            }
            else if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '(') {
                store.push(res);
                store.push(sign);
                res = 0; 
                sign = 1;
            } 
            // case c == ')'
            // we assume the paranthesis are balanced
            // and hence we do not check if the stack is empty
            else if (c == ')') {
                sign1 = store.top();
                store.pop();
                res1 = store.top();
                store.pop();
                res = sign1 * res + res1;
            }
            i++;
        }
        return res;
    }
};
