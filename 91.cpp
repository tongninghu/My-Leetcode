A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

class Solution {
public:
/*    void dfs(int& res, bool& flag, int start, string &s) {
        if(start == s.size() && flag == true) {
            res++;
            return;
        }
        for(int i = start; i < s.size() && i < (start + 2); i++) {
            int temp = stoi(s.substr(start, i - start + 1));
            if (temp <= 26 && temp >= 1 && s[start] != '0') {
                flag = true;
                dfs(res, flag, i + 1, s);
            }
        }
    }*/
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        vector<int> sum (s.length(), 0);
        sum[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            int temp = stoi(s.substr(i - 1, 2));
            if (temp <= 26 && temp >= 1) {
                if (i > 1) {
                    if (s[i - 1] == '0') sum[i] = sum[i - 1];
                    else if (s[i] == '0') sum[i] = sum[i - 2];
                    else sum[i] = sum[i - 1] + sum[i - 2];
                }
                else {
                    if (s[i - 1] == '0') sum[i] = sum[i - 1];
                    else if (s[i] == '0') sum[i] = 1;
                    else sum[i] = sum[i - 1] + 1;
                }
            }
            else if (temp > 26 && s[i] != '0') sum[i] = sum[i - 1];
            else return 0;
        }
        return sum[s.length() - 1];
    }
};
