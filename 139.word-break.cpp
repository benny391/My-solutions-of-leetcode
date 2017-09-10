class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int f[s.size() + 10];
        memset(f, -1, sizeof(f));
        for (int i = 0; i < s.size(); i++)
        {
            int lend = (i == 0? -1 : f[i -1]);
            do 
            {
                string wToFind = s.substr(lend + 1, i - lend);
                if (wordSet.find(wToFind) == wordSet.end())
                {
                    if (lend > 0)
                        lend = f[lend - 1];
                    else if (lend == 0)
                        lend = -1;
                    else if (lend == -1)
                        lend = -2;
                }
                else 
                {
                    f[i] = i;
                    break;
                }
            } while (lend != -2);
            if (f[i] != i && i > 0) 
            {
                f[i] = f[i - 1];
            }
        }
        return f[s.size() - 1] == s.size() - 1;
    }
};
