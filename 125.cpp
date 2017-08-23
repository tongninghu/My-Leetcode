Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

class Solution {
public:
bool isPalindrome(string s) {
    int i = 0, j = s.length() -1;
    while (i < j) { 
        while (!isalpha(s[i]) && !isdigit(s[i])) i++; 
        while (!isalpha(s[j]) && !isdigit(s[j])) j--; 
        if (i >= j) return true;
        if (toupper(s[i]) != toupper(s[j])) return false; 
        i++;
        j--;
    }   
    return true;
} 
};
