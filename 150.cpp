Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                store.push(stoi(tokens[i]));
            }
            else {
                int o2 = store.top();
                store.pop();
                int o1 = store.top();
                store.pop();
                int res;
                if (tokens[i] == "+") res = o1 + o2;
                else if (tokens[i] == "-") res = o1 - o2;
                else if (tokens[i] == "*") res = o1 * o2;
                else res = o1 / o2;
                store.push(res);
            }
        }
        return store.top();
    }
};
