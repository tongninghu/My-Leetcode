Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1

class Solution {
public:
    int nextGreaterElement(int n) {
        int counter = 0, prev = INT_MIN, index = INT_MAX;
        string input;
        while (n > 0) {
            if (n % 10 < prev && index == INT_MAX) index = counter;
            prev = n % 10;
            input += ('0' + prev);
            n /= 10;
            counter++;
        }
        if (index == INT_MAX) return -1;
        reverse(input.begin(), input.end());
        int j = input.size() - index - 1;
        for (int i = input.size() - 1; i > j; i--) {
            if (input[i] > input[j]) {
                swap(input[i], input[j]);
                reverse(input.begin() + j + 1, input.end());
                break;
            }
        }
        long res = stol(input);
        return (res > INT_MAX)? -1 : res;
    }
};
