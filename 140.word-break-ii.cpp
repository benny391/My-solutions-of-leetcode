class Solution 
{
    void genAns(string s, vector< vector<int> > &v, int i, string tmp, vector<string> &ans)
    {
        if (i == -1) 
        {
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }
        for (int j = 0; j < v[i].size(); j++)
        {
            genAns(s, v, v[i][j], s.substr(v[i][j] + 1, i - v[i][j]) + " " + tmp, ans);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int f[s.size() + 10];
        memset(f, -1, sizeof(f));
        vector< vector<int> > v;
        v.resize( s.size() );
        for (int i = 0; i < s.size(); i++)
        {
            int lend = ( i!= 0 ? f[i-1] : -1);
            while (lend != -2) 
            {
                string wToFind = s.substr(lend + 1, i - lend);
                if (wordSet.find(wToFind) != wordSet.end())
                {
                    f[i] = i;
                    v[i].push_back(lend);
                }
                if (lend > 0) 
                    lend = f[lend - 1];
                else if (lend == 0)
                    lend = -1;
                else lend = -2;
            }
            if (f[i] != i && i > 0) 
            {
                f[i] = f[i -1];
            }
        }
        vector<string> ret;
        if (f[s.size() - 1] == s.size() - 1) 
        {
            genAns(s, v, v.size() - 1, "", ret);
            return ret;
        }
        else
        {
            return {};
        }
    }
};
