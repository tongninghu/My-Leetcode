Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = 10 * res + x % 10;
            x = x / 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;
        else return res;
    }
};
