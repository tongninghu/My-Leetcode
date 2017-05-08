Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int low = 0, high = 0, sum = 0, base, add;
        for(high = low; high < words.size(); high = low) {
            sum = words[low].length();
            string t = words[low];
            while (sum < maxWidth && high < words.size() - 1)   sum += 1 + words[++high].length();
            if (sum > maxWidth) {
                sum = sum - 1 - words[high--].length();
                if (high == low) t += string(maxWidth - sum, ' ');
                else {
                    base = (maxWidth - sum) / (high - low) + 1;
                    add = (maxWidth - sum) - (maxWidth - sum) / (high - low) * (high - low);
                    for (int i = low + 1; i <= high; i++) {
                        if (i - low <= add)   t += string(base + 1, ' ') + words[i];
                        else t += string(base, ' ') + words[i];
                    }
                }
            }
            else if (sum == maxWidth && high > low) {
                for (int i = low + 1; i <= high; i++)
                    t += " " + words[i];
            }
            else if (sum < maxWidth && high == words.size() - 1) {
                for (int i = low + 1; i <= high; i++)
                    t += " " + words[i];
                t += string(maxWidth - sum, ' ');
            }
            res.push_back(t);
            low = high + 1;
        }
        return res;
    }
};
