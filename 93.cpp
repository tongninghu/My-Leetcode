Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    bool validString(string s) {
        int n = stoi(s);
        if (s[0] == '0' && s.length() > 1 || n > 255) return false;
        return true;
    }

    void helper(vector<string>& res, vector<string>& temp, int start, string s) {
        if (temp.size() == 4 && start == s.size()) {
            string t = temp[0];
            for (int i = 1; i < 4; i++) {
                t += '.';
                t += temp[i];
            }
            res.push_back(t);
            return;
        }
        for (int i = start; i < (start + 3) && i < s.length(); i++) {
            if (validString(s.substr(start, i - start + 1)) && (4 - temp.size() - 1) * 3 >= (s.length() - 1 - i)) {
                temp.push_back(s.substr(start, i - start + 1));
                helper(res, temp, i + 1, s);
                temp.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, temp;
        helper(res, temp, 0, s);
        return res;
    }
};
