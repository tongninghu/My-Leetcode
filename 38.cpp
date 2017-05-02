The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

class Solution {
public:
    string countAndSay(int n) {
        string s1, s2;
        s1 = {"1"};
        for (; n > 1; n--) {
            for (int i = 0; i < s1.length(); i++) {
                int count = 1;
                while ((i + 1) < s1.length() && s1[i + 1] == s1[i]) {
                    count++;
                    i++;
                }
                s2 += to_string(count);
                s2 += s1[i];
            }
            s1 = s2;
            s2 = {""};
        }
        return s1;
    }
};
