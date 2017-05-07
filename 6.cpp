The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) return s;
        for(int i = 0; i < numRows; i++) {
            int j = i, count = 0;
            while(j < s.length()) {
                res += s[j];
                if (i == 0 || i == numRows - 1) j += numRows * 2 - 2;
                else {
                    if (count % 2 == 0)  j += numRows * 2 - 2 - 2 * i;
                    else j += 2 * i;
                }
                count++;
            }
        }
        return res;
    }
};
