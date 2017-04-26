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
    void helper(vector<vector<int>>& graph, vector<int>& visited, int i, bool& flag) {
        visited[i] = 1;
        for (int j = 0; j <graph[i].size(); j++) {
            if (visited[j] == 0 && graph[i][j] == 1) helper(graph, visited, j, flag);
            else if (visited[j] == 1 && graph[i][j] == 1) flag = false;
        }
        visited[i] = 2;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>graph (numCourses, vector<int>(numCourses, 0));
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first][prerequisites[i].second] = 1;
        }
        vector<int> visited (numCourses, 0);
        bool flag = true;
        for(int i = 0; i < graph.size(); i++) {
             helper(graph, visited, i, flag); 
        }
        return flag;
    }
};
