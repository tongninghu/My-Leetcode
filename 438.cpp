Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, count = p.length();   
        vector<int> map (256, 0);
        vector<int> res;
        if (s.length() == 0 || p.length() == 0) return res;
        
        for (char i : p)
            map[i]++;
        
        while (right < s.length()) {
            if (map[s[right++]]-- > 0) count--;
            if (count == 0) res.push_back(left);
            if (right - left == p.length())
                if (map[s[left++]]++ >= 0) count++;
        }
        return res;
    }
};
