#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) 
            return INT_MAX;
        int sign;
        if ( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) )
            sign = 1;
        else 
            sign = -1;
        dividend = (dividend > 0) ? -dividend : dividend;
        divisor = (divisor > 0) ? -divisor : divisor;
        if (dividend > divisor) 
            return 0;
        vector< pair<int, int> > v;
        v.push_back(make_pair(divisor, -1));
        while (v.back().first > dividend)
        {
            if (v.back().first < -1073741824)
                break;
            v.push_back( make_pair(v.back().first + v.back().first, v.back().second + v.back().second) );
        }

        int ret = 0;
        for (auto iter = v.rbegin(); iter != v.rend(); iter++)
        {
            if (dividend - iter->first <=0) 
            {
                ret += iter->second;
                dividend -= iter->first;
            }
        }
        if (sign > 0)
        {
            if (ret == INT_MIN)
                return INT_MAX;
            return -ret;
        }
        return ret;
    }
};
