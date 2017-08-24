Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string {};
        sort(strs.begin(), strs.end());
        int i = 0, n = strs.size() - 1;
        while (i < strs[0].size() && i < strs[n].size() && strs[0][i] == strs[n][i]) i++;
        return strs[0].substr(0, i);
    }
};
