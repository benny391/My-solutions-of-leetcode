class Solution {
public:
    bool isRealMatch(const string &s, int sIdx, const string &p, int pIdx) {
        if (sIdx == s.size() || pIdx == p.size()) {
            while (p[pIdx] == '*') pIdx++;
            if (sIdx == s.size() && pIdx == p.size())
                return true;
            return false;
        }
        if (p[pIdx] == '*') 
        {
            if (pIdx < p.size() - 1 && p[pIdx] == p[pIdx + 1]) {
                return isRealMatch(s, sIdx, p, pIdx + 1);
            } else {
                return isRealMatch(s, sIdx + 1, p, pIdx) | isRealMatch(s, sIdx, p, pIdx + 1);
            }
        }
            
        if (s[sIdx] == p[pIdx] | p[pIdx] == '?')
            return isRealMatch(s, sIdx + 1, p, pIdx + 1);
        return false;
    }
    bool isMatch(string s, string p) {
        return isRealMatch(s, 0, p, 0);
    }
};
