/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]*/

class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            if (count < 0) return false;
        }
        if (count == 0) return true;
        else return false;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        queue<string> my_queue;
        unordered_set<string> my_set;
        vector<string> right;
        if (s.length() == 0) return vector<string> (1, "");
        my_queue.push(s);
        my_set.insert(s);
        bool found = false;
        while(!my_queue.empty()) {
            string p = my_queue.front();
            my_queue.pop();
            
            if (isValid(p)) {
                right.push_back(p);
                found = true;
            }
            
            for (int i = 0; i < p.length() && !found; i++) {
                if (p[i] == '(' || p[i] == ')') {
                    string t = p.substr(0, i) + p.substr(i + 1);
                    if (my_set.find(t) == my_set.end()) {
                        my_set.insert(t);
                        my_queue.push(t);
                    }
                }
            }
        }
        return right;
    }
};
