class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 10 && x >=0) 
            return true;
        if (x < 0 || x % 10 == 0)
            return false;
        int y = 0;
        do
        {
            y = y * 10 + (x % 10);
            x = x / 10;
        } while (x / 10 > y);

        if (x / 10 == y || x-y == 0)
        {
            return true;
        }
        return false;
    }
};
