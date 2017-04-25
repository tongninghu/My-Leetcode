Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:


/**
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
