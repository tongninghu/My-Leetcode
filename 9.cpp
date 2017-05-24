Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int num = 0;
        while(x > num) {
            num = 10 * num + x % 10;
            x = x / 10;
        }
        if (x == num || x == num / 10) return true;
        else return false;
    }
};
