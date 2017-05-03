Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    int stringToint(int start, int end, string &s) {
        int n = 0;
        if (end > start && s[start] == '0') return 256;
        for (int i = start; i <= end; i++) n = (n * 10 + s[i] - '0');
        return n;
    }
    
    vector<string> findIp(int start, int end, string &s) {
        vector<string> res;
        if ((end - start + 1) > 6 || (end - start + 1) < 2) return vector<string> ();
        for (int i = start; i <= start + 2 && i < end; i++) {
            int l = stringToint(start, i, s);
            int r = stringToint(i + 1, end, s);
            if (l <= 255 && r <= 255) {
                res.push_back(s.substr(start, i - start + 1) + "." + s.substr(i + 1, end - i));
            }
        }
        return res;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4) return vector<string> ();
        for (int i = 2; i <= s.length() - 2; i++) {
            vector<string> left = findIp(0, i - 1, s);
            vector<string> right = findIp(i, s.length() - 1, s);
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        res.push_back(left[j] + "." + right[k]);
                    }
                }
        }
        return res;
    }
};
