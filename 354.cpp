You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

class Solution {
    public:   
    struct compare {
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            if (p1.first == p2.first) return (p2.second < p1.second);
            else return (p1.first < p2.first);
        }
    } obj;
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), obj);   
        int res = 1;
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i].second > envelopes[j].second && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
