class Solution {
public:
    vector<string> letterCombinations(string digits) {
        digit2letters = { "",  "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> tmp({""}), v;
        for (int i = 0; i < digits.size(); i++)
        {
            v.clear();
            for (char c: digit2letters[digits[i] - '0'])
            {
                for (string s : tmp)
                {
                    s += c;
                    v.push_back(s);
                }
            }
            tmp = v;
        }
        return v;
    }

private:
    vector<string> digit2letters;

};
