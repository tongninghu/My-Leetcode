Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> bucket(24 * 60, false);
        for (string s : timePoints) {
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));
            if (!bucket[h * 60 + m]) bucket[h * 60 + m] = true;
            else return 0;
        }
        
        int low = INT_MAX, high = INT_MIN, diff = INT_MAX, prev = 0;
        for (int i = 0; i < 24 * 60; i++) {
            if (bucket[i]) {
                if (low != INT_MAX) {
                    diff = min(diff, i - prev);
                }
                low = min(low, i);
                high = max(high, i);
                prev = i;
            }
        }
        return min(diff, 24 * 60 - high + low);
    }
};
