#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp( pair<int, int> i, pair<int, int> j)
    {
        return i.first < j.first;
    }

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int idx = 0;
        vector< pair<int, int> > v;
        v.clear();
        for (int i : nums) 
        {
            v.push_back( make_pair(i, idx++) );
        }
        sort( v.begin(), v.end(), cmp );

        int l = 0, r = v.size() - 1;
        while (l < r) 
        {
            while ( (v[l].first + v[r].first) > target && (l < r) ) r--;
            while ( (v[l].first + v[r].first) < target && (l < r) ) l++;
            if ( (v[l].first + v[r].first == target) && (l < r))
            {
                return (v[l].second < v[r].second) ? vector<int>({v[l].second, v[r].second}): vector<int>({v[r].second, v[l].second});
            }
        }
        return vector<int>();
    }
};


