#include<cmath>

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
        {
            return 0;
        }
        int sign = x / abs(x);
        x = abs(x);
        unsigned int ret = 0;
        while (x > 0) 
        {
            if (ret > 214748364)
            {
                return 0;
            }
            ret = ret * 10 + (x % 10);
            x = x / 10;
        }
        return ret * sign;
    }
};
