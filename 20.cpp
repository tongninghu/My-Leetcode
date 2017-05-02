Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') res.push('(');
            else if (s[i] == '[') res.push('[');   
            else if (s[i] == '{') res.push('{');
            else if (res.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;
            else if (s[i] == ')') {
                if (res.top() != '(') return false;
                else res.pop();
            }
            else if (s[i] == ']') {
                if (res.top() != '[') return false;
                else res.pop();
            }
            else if (s[i] == '}') {
                if (res.top() != '{') return false;
                else res.pop();
            }
        }
        if (res.empty()) return true;
        else return false;
    }
};
