Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

/*
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
              
class Solution {
public:
    void DFS(UndirectedGraphNode *node, UndirectedGraphNode *root, unordered_map<int, UndirectedGraphNode *>& visited) {
        visited.insert(pair<int, UndirectedGraphNode *>(node->label, root));
        for(int i = 0; i < node->neighbors.size(); i++) {
            if (visited.find(node->neighbors[i]->label) == visited.end()) {
                UndirectedGraphNode *p = new UndirectedGraphNode(node->neighbors[i]->label);
                root->neighbors.push_back(p);
                DFS(node->neighbors[i], p, visited);
            }
            else root->neighbors.push_back(visited.find(node->neighbors[i]->label)->second);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<int, UndirectedGraphNode *> visited;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        DFS(node, root, visited);
        return root;
    }
};
