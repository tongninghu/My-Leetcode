Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

class Solution {
public:
    void DFS(vector<string>& res, vector<string>& cur, int start, long sum, char preSign, long preOper, string& num, int target) {
        if (num.size() == start && sum == target) {
            string t;
            for (int j = 0; j < cur.size(); j++) 
                t += cur[j];
            res.push_back(t);
            return;
        }
        
        for(int i = start; i < num.size(); i++) {
            long temp = stol(num.substr(start, i - start + 1));
            if (i != start && temp == stol(num.substr(start + 1, i -start))) break; // skip when multiple leading '0' exist.
            
            cur.push_back("+" + num.substr(start, i - start + 1));
            DFS(res, cur, i + 1, sum + temp, '+', temp, num, target);
            cur.pop_back();
            
            cur.push_back("-" + num.substr(start, i - start + 1));
            DFS(res, cur, i + 1, sum - temp, '-', temp, num, target);
            cur.pop_back();
            
            cur.push_back("*" + num.substr(start, i - start + 1));
            if (preSign == '+')       DFS(res, cur, i + 1, sum - preOper + preOper * temp, '+', preOper * temp, num, target);  
            else if (preSign == '-')  DFS(res, cur, i + 1, sum + preOper - preOper * temp, '-', preOper * temp, num, target);  
            else  DFS(res, cur, i + 1, sum * temp, '*', temp, num, target);  
            cur.pop_back();
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        vector<string> cur;
        for (int i = 0; i < num.size(); i++) {
            long temp = stol(num.substr(0, i + 1));
            if (i != 0 && temp == stol(num.substr(1, i))) break;
            cur.push_back(num.substr(0, i + 1));
            DFS(res, cur, i + 1, temp, ' ', temp, num, target);
            cur.pop_back();
        }
        return res;
    }
};
