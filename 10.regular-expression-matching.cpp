#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    vector<string> segParam(string p) {
        vector<string> ret;
        for (int i = 0; i < p.size(); i++)
        {
            if (i != p.size() - 1 && p[i + 1] == '*') {
                ret.push_back(p.substr(i,2));
                i++;
            }
            else {
                ret.push_back(p.substr(i,1));
            }
        }
        return ret;
    }
    bool isRealMatch(const string &s, int sIdx, vector<string> &pSeg, int pIdx)
    {
        if (s.size() == sIdx || pSeg.size()  == pIdx) {
            while (pIdx < pSeg.size() && pSeg[pIdx][1] == '*')
                pIdx++;
            if (s.size() == sIdx && pSeg.size() == pIdx) {
                return true;
            }
            return false;
        } 

        if (s.substr(sIdx, 1) == pSeg[pIdx] || pSeg[pIdx] == ".")
            return isRealMatch(s, sIdx + 1, pSeg, pIdx + 1);

        if (pSeg[pIdx].size() == 2) {
            if (s[sIdx] == pSeg[pIdx][0] || pSeg[pIdx][0] == '.') {
                return isRealMatch(s, sIdx + 1, pSeg, pIdx) || isRealMatch(s, sIdx, pSeg, pIdx + 1);
            }
            else {
                return isRealMatch(s, sIdx, pSeg, pIdx + 1);
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<string> pSeg =segParam(p);

        return isRealMatch(s, 0, pSeg, 0);
        
    }
};
