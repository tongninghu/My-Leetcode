Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

class Solution {
public:
    int numTrees(int n) {
        int num[n + 1] = {0}, sum;
        num[0] = 1;
        num[1] = 1;
        for (int j = 2; j <= n; j++) {
           sum = 0;    
           for (int i = 1; i <= j; i++) {
               sum = sum + num[i - 1] * num[j - i];
           }
           num[j] = sum;
        }
        return num[n];
    }
};
