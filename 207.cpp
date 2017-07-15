There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int> ());
        vector<int> degree (numCourses, 0);
        queue<int> q;
        int n = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            degree[prerequisites[i].first]++;
        }
        for (int j = 0; j < numCourses; j++)
            if (degree[j] == 0) q.push(j);
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            n++;
            for(int a : graph[t])
                if (--degree[a] == 0) q.push(a);
        }
        if (n == numCourses) return true;
        else return false;
    }
};
