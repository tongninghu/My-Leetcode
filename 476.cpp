Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

class Solution {
public:
    int findComplement(int num) {
        bool flag = false;
        for (int i = 31; i >= 0; i--) {
            if (num & 1 << i) flag = true;
            if (flag) num ^= 1 << i;
        }
        return num;
    }
};
