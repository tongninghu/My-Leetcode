You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

class Solution {
public:
    struct compare {
        bool operator() (vector<int> v1, vector<int> v2) {
            if (v1[0] == v2[0]) return (v1[1] < v2[1]);
            else return (v1[0] < v2[0]);
        }
    } obj;
    
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return 0;
        sort(pairs.begin(), pairs.end(), obj);
        vector<int> dp(pairs.size(), 1);
        int num = 1;
        for (int i = 1; i < pairs.size(); i++) {
            for ( int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            num = max(num, dp[i]);
        }
        return num;
    }
};
