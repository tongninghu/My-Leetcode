You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

class Solution {
public:
    struct compare {
        bool operator() (const pair<int, int> a, const pair<int, int> b){
            return a.first > b.first;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
        int max_temp = INT_MIN, len = INT_MAX;
        vector<int> res(2, 0);
        vector<int> index (nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++) {
            q.push(pair<int, int> (nums[i][0], i));
            max_temp = max(max_temp, nums[i][0]);
        }
        
        while(q.size() == nums.size()) {
            if((max_temp - q.top().first) < len) {
                res[0] = q.top().first;
                res[1] = max_temp;
                len = res[1] - res[0];
            }
            int i = q.top().second;
            q.pop();
            index[i]++;
            if (index[i] < nums[i].size()) {
                q.push(pair<int, int> (nums[i][index[i]], i));
                max_temp = max(max_temp, nums[i][index[i]]);
            }
        }
        return res;
    }   
};
