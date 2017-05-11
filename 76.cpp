Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

class Solution {
public:
    string minWindow(string s, string t) {
        int begin = 0, end = 0, counter = 0, d = INT_MAX, head;
        vector<int> res(128, 0);
        for (int i = 0; i < t.size(); i++) {
            res[t[i]]++;
        }
        counter = t.size();
        while(end < s.size()) {
            if (res[s[end++]]-- > 0) counter--;
            while(counter == 0) {
                if(end - begin < d) d = end - (head = begin);
                if(res[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX? "":s.substr(head, d);
    }
};
