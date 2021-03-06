Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, water = 0, h;
        while (left < right) {
            h = min(height[left], height[right]);
            water = max(water, h * (right - left));
            while(left < right && height[left] <= h) left++;
            while(left < right && height[right] <= h) right--;
        }
        return water;
    }
};
