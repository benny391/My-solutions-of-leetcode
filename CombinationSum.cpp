#include <vector>
using std::vector;

class Solution {
public:

    void generateComb(int i, const vector<int>& candidates, int target, vector<vector<bool>> &f, vector<int> comb, vector<vector<int>> &ret)
    {
        if (target == 0) 
        {
            ret.push_back(comb);
            return;
        }

        while (i >= 0)
        {
            if (f[i][target]) 
            {
                comb.push_back(candidates[i]);
                generateComb(i, candidates, target - candidates[i] , f, comb , ret);
                comb.pop_back();
            }
            i--;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector< vector<bool> > f(candidates.size(),vector<bool>(target + 10));
        bool g[target + 10];
        memset(g, false, sizeof(g));
        g[0] = true;
        for (int i = 0; i < candidates.size(); ++i)
            for (int j = candidates[i]; j <= target; j++)
            {
                if (g[ j - candidates[i]] )
                {
                    g[j] = true;
                    f[i][j] = true;
                }
            }
        vector<vector<int>> ret;
        if (!g[target]) 
        {
            return ret;
        }

        //generate combinations
        generateComb(candidates.size() - 1, candidates, target, f, vector<int>(),ret);
           
        return ret;

        
    }
};
