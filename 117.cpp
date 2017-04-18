Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *s = NULL, *p1 = root, *p2;
        while (p1) {
          while (p1) {
              if (!s) {
                  if (p1->left && !p1->right) {
                      s = p1->left;
                      p2 = s;
                  }
                  else if (!p1->left && p1->right) {
                      s = p1->right;
                      p2 = s;
                  }
                  else if (p1->left && p1->right) {
                      s = p1->left;
                      s->next = p1->right;
                      p2 = s->next;
                  }
                  
              }
              else {
                  if (p1->left) {
                      p2->next = p1->left;
                      p2 = p2->next;
                  }
                  if (p1->right) {
                      p2->next = p1->right;
                      p2 = p2->next;
                  }
               }
               p1 = p1->next;
           }
           p1 = s;
           s = NULL;
        }
    }
};
