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
    void merge(vector<Interval>& ret, Interval newInterval) {
        if (ret.empty() || ret.back().end < newInterval.start)
            ret.push_back(newInterval);
        else if (ret.back().end < newInterval.end)
            ret.back().end = newInterval.end;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        vector<Interval> ret;
        bool isInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if ( !isInserted ) {
                if (intervals[i].start < newInterval.start)
                    ret.push_back(intervals[i]);
                else {
                    isInserted = true;
                    merge(ret, newInterval);
                    i--;
                }
            } else {
                merge(ret, intervals[i]);
            }
        }
        if (!isInserted) {
            merge(ret, newInterval);
        }
        return ret;
    }
};
