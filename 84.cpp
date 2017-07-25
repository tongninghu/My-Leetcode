Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> index;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while(index.size() > 0 && heights[index.back()] >= heights[i]) {
                int h = heights[index.back()];
                index.pop_back();
                
                int pidx = (index.size() > 0)? index.back() : -1;
                res = max(res, h * (i - pidx - 1));
            }
            index.push_back(i);
        }
        return res;
    }
};
