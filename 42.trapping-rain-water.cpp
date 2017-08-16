#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
    static bool myfunc(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
    int trap(vector<int>& height) {
        vector<pair<int, int>> v;
        for (int i = 0; i < height.size(); i++)
            v.push_back(make_pair(height[i], i));
        sort(v.begin(), v.end() , myfunc);
        if (height.size() <= 2) 
            return 0;
        int l = min(v[0].second, v[1].second), r = max(v[0].second, v[1].second);
        int ret = (r - l - 1) * v[1].first;
        for (int i = 2; i < height.size(); i++)
        {
            if (v[i].first == 0)
                break;
            if (v[i].second > l && v[i].second < r) 
                ret -= v[i].first;
            else if (v[i].second < l)
            {
                ret += (l - v[i].second - 1) * v[i].first;
                l = v[i].second;
            }
            else
            {
                ret += (v[i].second - r - 1) * v[i].first;
                r = v[i].second;
            }
        }
        return ret;
    }
};
