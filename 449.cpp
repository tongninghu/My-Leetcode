Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string shelper(TreeNode* root) {
        string res;
        if (!root) return res;
        res += to_string(root->val);
        res += ",";
        res += shelper(root->left);
        res += shelper(root->right);
        return res;
    }
    
    TreeNode* dhelper(string& data, int max, int min, int& pos) {
        if (pos >= data.size()) return NULL;
        int cur_pos = pos, sum = 0;
        while (data[cur_pos] != ',') {
            sum = sum * 10 + data[cur_pos++] - '0';
        }
        if (sum <= min || sum >= max) return NULL;
        cur_pos++;
        pos = cur_pos;
        TreeNode* root = new TreeNode(sum);
        root->left = dhelper(data, sum, min, pos);
        root->right = dhelper(data, max, sum, pos);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = shelper(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        TreeNode* root = dhelper(data, INT_MAX, INT_MIN, pos);
        return root;
    }
};
