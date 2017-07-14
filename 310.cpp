For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

class Solution {
public:
    vector<unordered_set<int>> buildGraph(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph (n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }
        return graph;
    }
    
    queue<int> buildQueue(int n, vector<unordered_set<int>> &graph) {
        queue<int> LEAF;
        for(int i = 0; i < n; i++) {
            if (graph[i].size() == 1) LEAF.push(i);
        }
        return LEAF;
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (edges.size() == 0) return vector<int>(1, 0);
        else if (n == 2 && edges.size() == 1) return vector<int> {0, 1};
        vector<unordered_set<int>> graph = buildGraph(n, edges);
        queue<int> LEAF = buildQueue(n, graph);
        vector<int> res;

        while(n > 2) {      
            int size = LEAF.size();
            for (int i = 0; i < size; i++) {
                int leaf = LEAF.front();
                LEAF.pop();
                for (int a : graph[leaf]) {
                    graph[a].erase(leaf);
                    if (graph[a].size() == 1) LEAF.push(a);
                }
            }
            n -= size;
        }
        while (!LEAF.empty()) {
            res.push_back(LEAF.front());
            LEAF.pop();
        }
        return res;
    }
};
