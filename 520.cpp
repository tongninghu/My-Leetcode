Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1) return true;
        else if (word.length() > 1) {
            if (word[0] < 'a' && word[word.length() - 1] < 'a') {
                for (int i = 1; i < word.length() - 1; i++) {
                    if (word[i] >= 'a') return false;
                }
                return true;
            }
            else if (word[0] < 'a') {
                for (int i = 1; i < word.length(); i++)
                    if (word[i] < 'a') return false;
                return true;
            }
            else {
                for (int i = 0; i < word.length(); i++)
                    if (word[i] < 'a') return false;
                return true;
            }
        }
    }
};
