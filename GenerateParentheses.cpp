class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ret;
        realGenerateParenthesis("", 0, 0, n, ret);
        return ret;
    }

    void realGenerateParenthesis(string curPat, int lp, int rp, int n, vector<string> &ret)
    {
        if (lp < n) 
        {
            realGenerateParenthesis(curPat + "(", lp + 1, rp, n, ret);
            if (rp < lp)
                realGenerateParenthesis(curPat + ')', lp, rp +1, n, ret);
        }
        else if (lp == n)
        {
            if (rp < n)
                realGenerateParenthesis(curPat + ')', lp, rp +1, n, ret);
            else if (rp == n)
                ret.push_back(curPat);
        } 
    }
};
