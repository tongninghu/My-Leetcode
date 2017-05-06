Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
private:
    unordered_map<int, vector<string>> map = {{2,{"a","b","c"}}, {3,{"d","e","f"}}, {4,{"g","h","i"}}, {5,{"j","k","l"}}, {6,{"m","n","o"}}, {7,{"p","q","r","s"}}, {8,{"t","u","v"}}, {9,{"w","x","y", "z"}}};
public:
    void dfs(vector<string>& res, vector<string>& cur, int start, string digits, bool& flag) {
        if (start == digits.size()) {
            string t;
            for(int i = 0; i < cur.size(); i++) {
                t += cur[i];
            }
            res.push_back(t);
            return;
        }
        unordered_map<int, vector<string>>::iterator itr = map.find(digits[start] - '0');
        if (itr == map.end()) {
            flag = false;
            return;
        }
        for(int i = 0; i < itr->second.size(); i++) {
            cur.push_back(itr->second[i]);
            dfs(res, cur, start + 1, digits, flag);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> cur;
        bool flag = true;
        dfs(res, cur, 0, digits, flag);
        if (flag && digits.size() > 0) return res;
        else return vector<string> ();
    }
};
