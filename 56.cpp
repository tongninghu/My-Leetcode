/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution {
public:
    static bool intervalcomp(Interval a, Interval b) { return (a.start < b.start); }

    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return vector<Interval> ();
        sort(intervals.begin(), intervals.end(), intervalcomp);
        vector<Interval> my_vector;
        my_vector.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size()) {
            if (my_vector.back().end >= intervals[i].start) {
                if (my_vector.back().end < intervals[i].end)  my_vector.back().end = intervals[i].end;
            }
            else my_vector.push_back(intervals[i]);
            i++;
        }
        return my_vector;
    }
};
