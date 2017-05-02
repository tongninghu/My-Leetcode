Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
        string s;
        vector<int> my_int {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        unordered_map<int, string> my_map {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"},{500, "D"}, {900, "CM"}, {1000, "M"}};
        int c, d = 10;
        while (num > 0) {
            c = num % d;
            num -= c;
            int i = upper_bound(my_int.begin(), my_int.end(), c) - my_int.begin();
            string s2 = my_map[my_int[i - 1]];
            while ((c - my_int[i - 1]) > 0) {
                s2 = s2 + my_map[d / 10];
                c = c - d / 10;
            }
            d = d * 10;
            s = s2 + s;
        }
        return s;
    }
};
