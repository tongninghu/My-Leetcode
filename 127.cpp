Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.

class Solution {
public:
    vector<string> findString(string s, unordered_set<string>& my_set) {
        vector<string> res;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                string temp = s;
                if (s[i] != 'a' + j) {
                    temp[i] = (char)'a' + j;
                    if(my_set.find(temp) != my_set.end()) {
                        res.push_back(temp);
                        my_set.erase(temp);
                    }
                }
            }
        }
        return res;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> my_queue;
        unordered_set<string> my_set;
        for (int i = 0; i < wordList.size(); i++) 
            my_set.insert(wordList[i]);
        my_queue.push({beginWord, 1});

        while (!my_queue.empty()) {
            string t = my_queue.front().first;
            int num = my_queue.front().second;
            my_queue.pop();
            if (t != endWord) {
                vector<string> temp = findString(t, my_set);
                for(int j = 0; j < temp.size(); j++) {
                    my_queue.push({temp[j], num + 1});
                }
            }
            else return num;
        }
        return 0;
    }
};
