Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
        string s;
        vector<int> my_int {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        unordered_map<int, string> my_map {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"},{500, "D"}, {900, "CM"}, {1000, "M"}};
        for (int i = my_int.size() - 1; i >= 0; i--) {
            for (int n = 0; n < num / my_int[i]; n++) {
                s += my_map[my_int[i]];
            }
            num = num - num / my_int[i] * my_int[i];
        }
        return s;
    }
};
