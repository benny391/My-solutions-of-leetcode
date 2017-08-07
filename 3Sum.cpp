#include <vector>
#include <unordered_set>
#include <algorithm>
using std::sort;
using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        unordered_set<int> s;
        vector<vector<int> > ret;
        int zero_num = 0;
        for (int i : nums) {
            s.insert( i );
            if (i == 0) 
                zero_num ++;
        }
        if (zero_num > 2) 
            ret.push_back(vector<int>({0, 0, 0}));
        sort( nums.begin(),  nums.end() );
        if (zero_num > 0) {
            for (int i = 0; i < nums.size() && nums[i] < 0; ++i)
                if (s.find( -nums[i] ) != s.end() and (i == 0 || nums[i] != nums[i-1] )) 
                    ret.push_back(vector<int>({nums[i], 0, -nums[i]}));
        }

        for (int i = 0; i < nums.size() ; ++i)
            if (i == 0 || nums[i] != nums[i-1])
            {
                for (int j = i + 1; j < nums.size(); ++j)
                    if (j == i+1 || nums[j] != nums[j-1])
                    { 
                        if (nums[i] != 0 && nums[i] / abs(nums[i]) * nums[j] > 0) {
                            if (s.find( -nums[i] - nums[j] ) != s.end()) 
                                ret.push_back(vector<int>({nums[i], nums[j], -nums[i] - nums[j]}));
                        }
                    }
            }

        return ret;
        
    }
};
