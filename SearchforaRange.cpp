#include <vector>
using std::vector;

class Solution {
public:
    int binarySearch(vector<int>&nums, int target, bool lrSwitch) {
        int l = 0, r = nums.size(), mid, ret = -1;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > target) 
            {
                r = mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else 
            {
                if (lrSwitch == false && mid > 0 && nums[ mid - 1] == target)
                {
                    r = mid;
                    continue;
                }
                if (lrSwitch == true && mid < nums.size() - 1 && nums[mid + 1] == target)
                {
                    l = mid + 1;
                    continue;
                }
                ret = mid;
                break;
            }
        } 
        return ret;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int left = binarySearch(nums, target, false);
        if (left == -1) {
            return vector<int>({-1, -1});
        }
        int right = binarySearch(nums, target, true);
        return vector<int>({left, right});
    }
};
