class Solution {
public:
    string convert(string s, int numRows) {
        int modulus = numRows * 2 - 2;
        if (modulus < 1) 
            modulus = 1;
        string ret;
        ret.clear();
        for (int i = 0; i < numRows; ++i)
        {
            int j = i;
            while (j < s.size())
            {
                if ( i == 0 or i == numRows - 1) 
                {
                    ret.push_back(s[j]);
                    j+=modulus;
                }
                else
                {
                    ret.push_back(s[j]);
                    if (j + modulus - i - i < s.size()) 
                    {
                        ret.push_back(s[j+modulus-i-i]);
                    }
                    j+=modulus;
                }
            }
        }
        return ret;
    }
};

