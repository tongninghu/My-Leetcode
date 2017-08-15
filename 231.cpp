Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag = 0;
        if (n < 0) return false;
        
        for (int i = 0; i < 32; i++) {
            if (1 & n >> i) flag++;
            if (flag > 1) return false;
        }
        if (flag == 1) return true;
        else return false;
    }
};
