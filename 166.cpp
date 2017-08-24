Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res, fraction;
        long num = numerator, den = denominator;
        if (num < 0 && den > 0) {
            num = -num;
            res += '-';
        }
        if (num > 0 && den < 0) {
            den = -den;
            res += '-';
        }
        if (num < 0 && den < 0) {
            num = -num;
            den = -den;
        }

        
        unordered_map<long, long> pre;
        long remain = num, counter = 1;
        if (num >= den) {
            res += to_string(num / den);
            remain = num % den;
        }
        else {
            res += '0';
        }
        
        while (remain != 0) {
            if (pre.find(remain) == pre.end()) {
                pre[remain] = counter++;
            }
            else {
                counter++;
            }
            long s = remain * 10 % den;
            if (pre.find(s) != pre.end()) {
                fraction += to_string(remain * 10 / den);
                fraction.insert(fraction.end() - (counter - pre[s]), '(');
                fraction += ')';
                break;
            }
            else {
                fraction += to_string(remain * 10 / den);
                remain = s;
            }
        }
        if (fraction.size() > 0) {
            res += '.';
            res += fraction;
        }
        return res;
    }
};
