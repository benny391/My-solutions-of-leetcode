class Solution {
public:
    bool isLarestPermutation(vector<int>& nums)
    {
        for (int i = 0; i < nums.size() -1; i++)
        {
            if (nums[i] < nums[i + 1])
                return false;
        }
        return true;
    }
    void nextPermutation(vector<int>& nums) {
        if (isLarestPermutation(nums)) {
            for (int i = 0; i < nums.size() / 2; i++)
            {
                int tmp = nums[i];
                nums[i] = nums[nums.size() - i - 1];
                nums[nums.size() - i - 1] = tmp;
            }
            return;
        }

        for (auto iter = nums.rbegin(); iter != nums.rend(); iter++)
        {
            if ( *(iter + 1) < *iter)
            {
                auto it = nums.rbegin();
                for ( ;*it <= *(iter + 1); it++);
                int tmp = *it;
                *it = *(iter + 1);
                *(iter + 1) = tmp;
                reverse(nums.rbegin(), iter + 1);
                return;
            }
        }
    }
};
