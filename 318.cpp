Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> index(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                index[i] |= 1 << (words[i][j] - 'a');
        
        for (int i = 0; i < index.size(); i++)
            for (int j = i + 1; j < index.size(); j++) 
                if ((index[i] & index[j]) == 0 && words[i].size() * words[j].size() > res) res = words[i].size() * words[j].size();
        
        return res;
    }
};
