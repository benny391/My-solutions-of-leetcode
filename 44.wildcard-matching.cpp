#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector<bool >> f(s.size(), vector<bool>(p.size()));
        if (s.empty()) {
            while (!p.empty() && p[0] == '*')
                p.erase(0,1);
            return p.empty();
        }
        if (p.empty())
            return false;

        bool isAlwayStar = true;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < p.size(); j++)  {
                if (i == 0) {
                    if (isAlwayStar) {
                        if (s[i] == p[j]  || p[j] == '?' || p[j] == '*' ) {
                            f[i][j] = true;
                            if (p[j] == '*') isAlwayStar = true;
                            else isAlwayStar = false;
                        } 
                        else break;
                    } 
                    else {
                       if (p[j] == '*') f[i][j] = true;
                       else break;
                    }
                }
                else if (j != 0) {
                    if (s[i] == p[j] || p[j] == '?')
                        f[i][j] = f[i-1][j-1];
                    else if (p[j] == '*') 
                        f[i][j] = f[i-1][j-1] | f[i][j-1] | f[i -1][j];
                    else 
                        f[i][j] = false;
                } else {
                    if (p[j] == '*') f[i][j] = true;
                    else f[i][j] = false;
                }
        }
        return f[s.size() - 1][p.size() - 1];
    }
};
