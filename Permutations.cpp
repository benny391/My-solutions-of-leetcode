class Solution {
public:
    int nextPermutation(vector<int>& nums)
    {
        int i, j;

        for (i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i+1])
            {
                break;
            }
        }
        if (i < 0) 
            return -1;
        
        for (j = nums.size() - 1; j > i; j--)
        {
            if (nums[j] > nums[i]) 
            {
                swap(nums[j], nums[i]);
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        return 0;

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        ret.clear();
        do {
            ret.push_back(nums);
        } while ( nextPermutation(nums) != -1);
        return ret;
    }
        
};

