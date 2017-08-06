class Solution {
public:
    string longestPalindrome(string s) {
        //init
        int f[2][2000];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < s.size(); ++i)
        {
            f[0][i] = f[1][i] = 1;
        }

        int max = 1;
        string res;
        res = s.substr(0, 1);
        for (int i = 2; i <= s.size(); ++i)
        {
            for (int j = 0; j <= s.size() - i; ++j)
            {
                if ((f[i % 2][j+1] > 0) && (s[j] == s[j+i-1]))
                {
                    max = i;
                    f[i % 2][j] = 1;
                    res = s.substr(j, i);
                }
                else 
                {
                    f[i % 2][j] = 0;
                }
            }
            if (max < i - 1)
            {
                break;
            }
        }
        return res;
    }
};
