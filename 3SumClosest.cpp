
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0, minDiff = 2147483647; 
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < minDiff) 
                {
                    ret = sum;
                    minDiff = abs(target - sum);
                }

                if (target - sum > 0) j++;
                else k--;
            }
        }
        return ret;
    }
};
