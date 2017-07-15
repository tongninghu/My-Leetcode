There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

class Solution {
public:
    vector<unordered_set<int>> buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph (numCourses);
        for(int i = 0; i < prerequisites.size(); i++) 
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        return graph;
    }
    
    vector<int> buildDegree(int numCourse, vector<pair<int, int>>& prerequisites) {
        vector<int> degree (numCourse, 0);
        for(int i = 0; i < prerequisites.size(); i++) 
            degree[prerequisites[i].first]++;
        return degree;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> degree = buildDegree(numCourses, prerequisites);
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) 
                if (degree[j] == 0) break;
            if (j == numCourses) return vector<int> ();
            degree[j] = -1;
            res.push_back(j);
            for (int a : graph[j]) 
                degree[a]--;
        }
        return res;
    }
};
