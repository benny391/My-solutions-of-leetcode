class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid, ret = -1;
        while (l < r)
        {   
            mid = (l + r) / 2;
            if (nums[mid] > nums[l]) 
            {
                if (nums[mid] == target)
                {
                    ret = mid;
                    break;
                }
                else if (nums[mid] > target && target >= nums[l]) 
                {
                    r = mid;
                }
                else 
                {
                    l = mid + 1;
                }
            }
            else 
            {
                if ( nums[mid] == target ) 
                {
                    ret = mid;
                    break;
                }
                else if (nums[mid] < target && target <= nums[r - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
        }
        return ret;
    }
};
