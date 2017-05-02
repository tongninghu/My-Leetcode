Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        unordered_map <char, int> my_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0, j = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if(my_map[s[i]] >= j)  num += my_map[s[i]];
            else  num -= my_map[s[i]];
            j = my_map[s[i]];
        }
        return num;
    }
};
