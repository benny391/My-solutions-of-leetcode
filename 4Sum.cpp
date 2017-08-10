class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ret({});
        if (nums.size() < 4) 
            return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
            if (i == 0 || nums[i] != nums[i-1])
                for (int j = i + 1; j < nums.size() - 2; j++)
                    if (j == i+1 || nums[j]  != nums[j-1])
                    {
                        int k = j+1, l = nums.size() - 1;
                        while (k < l) 
                        {
                            int sum = nums[i] + nums[j] + nums[k] + nums[l];
                            if (sum == target) 
                            {
                                if (ret.size() == 0 || ret.back() != vector<int>({nums[i], nums[j], nums[k], nums[l]}))
                                    ret.push_back({nums[i], nums[j], nums[k], nums[l]});
                                k++;
                            }
                            else if (sum < target) 
                            {
                                k++;
                            }
                            else 
                            {
                                l--;
                            }
                        }
                    }
        return ret;
    }
};

