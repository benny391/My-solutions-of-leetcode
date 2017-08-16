class Solution {
public:
    char reverseParen(char x)
    {
        switch (x)
        {
            case '(':return ')';
            case '[':return ']';
            case '{':return '}';
        }
        return x;
    }
    bool isValid(string s) {
        stack<char> st;
        
        for (auto it = s.begin(); it != s.end();it++) {
            if (*it == '[' || *it == '{' || *it == '('){
                st.push(*it);
            }
            else {
                if (!st.empty() && reverseParen(st.top()) == *it) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
