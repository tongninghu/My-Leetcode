Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int i = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (arr[i] != x) {
            i--;
        }
        int j = i + 1;
        
        while (res.size() < k) {
            if (i >= 0 && j < arr.size() && abs(arr[i] - x) <= abs(arr[j] - x) || j == arr.size()) {
                res.push_back(arr[i--]);
            }
            else if (i >= 0 && j < arr.size() && abs(arr[i] - x) > abs(arr[j] - x) || i < 0) {
                res.push_back(arr[j++]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
