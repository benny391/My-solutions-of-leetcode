
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        bool f[target + 10];
        memset(f, false, sizeof(f));
        vector<vector<bool>> g(candidates.size(), vector<bool>(target + 10));
        sort(candidates.begin(), candidates.end());


        f[0] = true;
        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = target; j >= candidates[i]; j--)
            {
                if (f[j - candidates[i]]) 
                {
                    f[j] = true;
                    g[i][j] = true;
                }
            }
        }

        vector<vector<int>> ret({});
        generateComb(candidates.size() -1, vector<int>(), candidates, target, g, ret);

        return ret;
    }

    void generateComb(int idx,  vector<int> comb, const vector<int>& candidates, int target, const vector<vector<bool>> &g, vector<vector<int>> &ret)
    {
        if (idx < 0 && target !=0) return;
        if (target == 0)
        {
            ret.push_back(comb);
            return;
        }
        if (g[idx][target])
        {
            comb.push_back(candidates[idx]);
            generateComb(idx - 1, comb, candidates, target - candidates[idx], g, ret);
            comb.pop_back();
        }
        while (idx > 0 && candidates[idx] == candidates[idx-1])
            idx--;
        generateComb(idx - 1 , comb, candidates, target, g, ret);
    }
};
