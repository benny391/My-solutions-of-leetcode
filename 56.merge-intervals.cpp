/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class MyFunc {
public:
    bool operator() (Interval a, Interval b){
        return a.start < b.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), MyFunc());
        vector<Interval> ret;
        if (intervals.empty()) 
            return ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret.back().end >= intervals[i].start) {
                if (ret.back().end < intervals[i].end)
                    ret.back().end = intervals[i].end;
            }
            else 
                ret.push_back(intervals[i]);
        }
        return ret;
    }
};
