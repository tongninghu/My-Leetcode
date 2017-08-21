Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

class Solution {
public:
    int calculate(string s) {
        stack<int> my_stack;
        char sign = '+';
        int num = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {         
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1) {
                if (sign == '+') {
                    my_stack.push(num);
                }
                else if (sign == '-') {
                    my_stack.push(-num);
                }
                else if (sign == '*') {
                    int prev = my_stack.top();
                    my_stack.pop();
                    my_stack.push(prev * num);
                }
                else {
                    int prev = my_stack.top();
                    my_stack.pop();
                    my_stack.push(prev / num);            
                }
                sign = s[i];
                num = 0;
            } 
        }
        while (!my_stack.empty()) {
            res += my_stack.top();
            my_stack.pop();
        }
        return res;
    }
};
