Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        long n = 0;
        int s = 0, sign = 0;
        while (str[s] == ' ') s++;
        
        if (isdigit(str[s])) n = str[s] - '0';
        else if ((str[s]) == '-') sign = - 1;
        else if ((str[s]) == '+') sign = 0;
        else return 0;
        
        for (int i = s + 1; i < str.size() && isdigit(str[i]); i++) {
            n = n * 10 + str[i] - '0';
            if (sign == 0 && n > INT_MAX) {
                n = INT_MAX;
                break;
            }
            else if (sign == -1 && n > INT_MAX) {
                n = INT_MAX + 1;
                break;
            }
        }
        if (sign == -1) return (0 - n);
        else return n;
    }
};
