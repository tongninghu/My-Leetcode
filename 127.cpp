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
    bool isOnebit(string s, string compare) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != compare[i]) count++;
        }
        return (count == 1)? true : false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> my_queue;
        unordered_set<string> my_set;
        unordered_map<string, int> my_map;
        for (int i = 0; i < wordList.size(); i++) 
            my_set.insert(wordList[i]);
        my_queue.push(beginWord);
        my_map[beginWord] = 1;
        while (!my_queue.empty()) {
            string t = my_queue.front();
            my_queue.pop();
            if (t != endWord) {
                for (unordered_set<string>::iterator itr = my_set.begin(); itr != my_set.end(); ) {
                    unordered_set<string>::iterator current = itr;
                    unordered_set<string>::iterator next = ++itr;
                    if (isOnebit(t, *current)) {
                        my_queue.push(*current);
                        my_map[*current] = my_map[t] + 1;
                        my_set.erase(*current);
                        itr = next;
                    }
                    else itr = next;
                }
            }
            else return my_map[t];
        }
        return 0;
    }
};
