Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int s;
            if (i == digits.size() - 1) 
                s = digits[i] + 1 + c;   
            else 
                s = digits[i] + c;
            c = s / 10;
            s = s % 10;
            digits[i] = s;
        }
        if (c > 0) digits.insert(digits.begin(), c);
        return digits;
    }
};
