Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
  
  class Solution {
public:
    vector<vector<string>> backtrack(string beginWord, string endWord, unordered_map<string, vector<string>>& father) {
        vector<vector<string>> res;
        if (beginWord == endWord) {
            vector<string> k = {endWord};
            res.push_back(k);
            return res;
        }
        else {
            for(auto m : father[endWord]) {
                vector<vector<string>> z = backtrack(beginWord, m, father);
                for (auto n : z) {
                    n.push_back(endWord);
                    res.push_back(n);
                }      
            }
        }
        return res;
    }
               
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> d;
        unordered_map<string, vector<string>> father;
        queue<string> my_queue;
        vector<vector<string>> res;
        int min = INT_MAX;
        for (auto s : wordList) 
            d[s] = INT_MAX;
        my_queue.push(beginWord);
        d[beginWord] = 0;
        while (!my_queue.empty()) {
            string t = my_queue.front();
            my_queue.pop();  
            int step = d[t] + 1;
            for (int i = 0; i < t.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    string temp = t;
                    if (t[i] != 'a' + j) {
                        temp[i] = (char)'a' + j;
                        if (d.find(temp) != d.end()) {
                            if (step > d[temp]) continue;
                            else if (step < d[temp]) {
                                d[temp] = step;
                                my_queue.push(temp);
                            }
                            
                            if (father.find(temp) == father.end()) {
                                vector<string> m = {t};
                                father[temp] = m;
                            }
                            else {
                                father[temp].push_back(t);
                            }
                            if (temp == endWord) min = step;
                        }
                    }
                }
            }
        }

        res = backtrack(beginWord, endWord, father);
        return res;
    }
};
