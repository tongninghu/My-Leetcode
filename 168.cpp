Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    
    class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int c = 0;
        while(n > 0) {
            c = (n - 1) % 26;
            n = (n - 1) / 26;
            res += 'A' + c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
