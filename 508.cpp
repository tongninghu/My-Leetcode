Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root, unordered_map<int, int>& map, int& counter) {
        if (!root) return 0;
        int l = sum(root->left, map, counter);
        int r = sum(root->right, map, counter);
        int s = l + r + root->val;
        map[s]++;
        counter = max(counter, map[s]);
        return s;
    }
        
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        int counter = 0;
        vector<int> res;
        int a = sum(root, map, counter);
        for (unordered_map<int, int>::iterator itr = map.begin(); itr != map.end(); itr++) {
            if ((*itr).second == counter) {
                res.push_back((*itr).first);
            }
        }
        return res;
    }
};
