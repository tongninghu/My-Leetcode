Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int ssize = s1.size();
        if (ssize == 0) return true;
        else if (ssize == 1) return s1 == s2;
        
        bool s[ssize + 1][ssize][ssize];
        for (int i = 0; i < ssize; i++) {
            for (int j = 0; j < ssize; j++) {
                s[1][i][j] = s1[i] == s2[j];
            }
        }
        for(int length = 2; length <= ssize; length++) {
            for (int i = 0; i <= ssize - length; i++) {
                for (int j = 0; j <= ssize - length; j++) {
                    s[length][i][j] = false;
                    for(int k = 1; k < length && !s[length][i][j]; k++) {
                        s[length][i][j] = s[length][i][j] || s[k][i][j] && s[length - k][i + k][j + k];
                        s[length][i][j] = s[length][i][j] || s[k][i + length - k][j] && s[length - k][i][j + k];
                    }
                }
            }
        }
        return s[ssize][0][0];
    }
};
