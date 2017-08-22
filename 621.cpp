Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> res (26, 0);
        for (char s : tasks)
            res[s - 'A']++;
    
        sort(res.begin(), res.end());  
        
        int i = 24;
        for (; i >= 0; i--) {
            if (res[i] < res[25]) break;
        }

        return max(int(tasks.size()), (res[25] - 1) * (n + 1) + 25 - i);
    }
};