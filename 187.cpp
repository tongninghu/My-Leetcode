All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> F;
        unordered_set<int> R;
        vector<string> res;
        vector<int> map(26, 0);
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;
        for (int i = 0; i + 9 < s.size(); i++) {
            int v = 0;
            for (int j = i; j < i + 10; j++) {
                v <<= 2;
                v |= map[s[j] - 'A'];
            }
   
            if (F.find(v) != F.end() && R.find(v) == R.end()) {
                res.push_back(s.substr(i, 10));
                R.insert(v);
            }
            else F.insert(v);
        }
        return res;
    }
};
