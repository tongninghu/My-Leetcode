You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

class Solution {
private:
    struct Node {
        int val, sum, dup;
        Node *left;
        Node *right;
        Node(int x) : val(x), sum(0), dup(1), left(NULL), right(NULL) {}
    };
    
public:
    Node* insert(Node *root, int i, int s, vector<int>& res) {
        if (!root) root = new Node(s);
        else if (root->val == s) {
            root->dup += 1;
            res[i] += root->sum;
        }   
        else if (root->val > s) {
            root->left = insert(root->left, i, s, res);
            root->sum += 1;
        }
        else {
            root->right = insert(root->right, i, s, res);
            res[i] += (root->sum + root->dup);
        }
        return root;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        Node* root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--)
            root = insert(root, i, nums[i], res);
        return res;
    }
};
