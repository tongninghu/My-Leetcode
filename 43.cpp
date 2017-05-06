Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string multiplyLast(string& num1, int a) {
        int s = 0, c = 0;
        string res;
        for(int i = num1.size() - 1; i >=0; i--) {
            s = (num1[i] - '0') * a + c;
            c = s / 10;
            s = s % 10;
            res += '0' + s;
        }
        if (c > 0) res += '0' + c;
        reverse(res.begin(), res.end());
        return res;
    }
    string addTwoString(string& num1, string& num2) {
        if(num1.size() == 0) return num2;
        else if(num2.size() == 0) return num1;
        string t;
        int i = num1.size() - 1, j = num2.size() - 1, s = 0, c = 0;
        while((i >= 0) || (j >= 0) || (c > 0)) {
            s = c;
            if (i >= 0) {
                s += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                s += num2[j] - '0';
                j--;
            }
            c = s / 10;
            s = s % 10;
            t.push_back('0' + s);
        }
        reverse(t.begin(), t.end());
        return t;
    }
    string multiply(string num1, string num2) {
        vector<string> mul;
        string res;
        if(num2.length() > num1.length()) return multiply(num2, num1);
        if (num2 == "0") return string ("0");
        int operand;
        for(int i = num2.length() - 1; i >= 0; i--) {
            operand = num2[i] - '0';
            mul.push_back(multiplyLast(num1, operand));
        }
        for (int j = 0; j < mul.size(); j++) {
            for (int n = j; n > 0; n--) {
                mul[j].push_back('0');
            }
            res = addTwoString(res, mul[j]);
        }
        return res;
    }
};
