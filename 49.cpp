Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            unordered_map<string, vector<string>>::iterator itr = map.find(t);
            if(itr != map.end()) itr->second.push_back(strs[i]);
            else map[t] = vector<string> (1, strs[i]);
        }
        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator itr = map.begin(); itr != map.end(); itr++) {
            res.push_back(itr->second);
        }
        return res;
    }
};
