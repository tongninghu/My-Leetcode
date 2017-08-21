Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int pa = a.size() - 1, pb = b.size() - 1, c = 0;
        while (pa >= 0 || pb >= 0) {
            int s = c;
            if (pa >= 0) 
                s += a[pa--] - '0';
            if (pb >= 0)
                s += b[pb--] - '0';
            c = s / 2;
            s = s % 2;
            res += ('0' + s);
        }
        if (c) res += ('0' + c);
        reverse(res.begin(), res.end());
        return res;
    }
};
