#include<string>
#include<vector>
#include<cstdlib>
#include<iostream>

using namespace std;

class BigNum {
    public:
        BigNum(string num = "0");
        BigNum(BigNum &num);
        BigNum operator*(const BigNum &num);
        string toString();
    private:
        vector<int> v;
        static const int UNIT = 4;
        static const int D[UNIT + 1];
};
const int BigNum::D[UNIT + 1] = {1, 10, 100, 1000, 10000};

BigNum::BigNum(string num)  {
    for (auto it = num.rbegin(); it != num.rend(); it++)
    {
        if ((it - num.rbegin()) % UNIT == 0) {
            v.push_back(*it - '0');
        }
        else {
            v.back() = v.back() + (*it - '0') * D[ (it - num.rbegin()) % UNIT];
        }
    }
}

BigNum::BigNum(BigNum &num) {
    v.resize(num.v.size());
    for (int i = 0; i < num.v.size(); i++)
    {
        v[i] = num.v[i];
    }
}

BigNum BigNum::operator*(const BigNum &num)
{
    BigNum ret;
    ret.v.resize(num.v.size() + v.size());
    for (auto it = ret.v.begin(); it != ret.v.end(); it++)
        *it = 0;
    int k;
    for (int i = 0; i < num.v.size(); i++)
    {
        k = 0;
        for (int j = 0; j < v.size(); j++)
        {
            int tmp = (ret.v[j + i] + v[j] * num.v[i] + k);
            ret.v[ j + i] = tmp % D[UNIT];
            k = tmp / D[UNIT];
        }
        ret.v[ v.size() + i] += k;
    }
    int rSize = num.v.size() + v.size();
    while (ret.v[rSize - 1] == 0 && rSize > 1) rSize--;
    ret.v.resize(rSize);
    return ret;
}

string BigNum::toString()
{
    string ret, tmp;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        tmp = to_string(*it);
        while (tmp.size() < 4 && it != v.rbegin()) 
            tmp = "0" + tmp;
        ret += tmp;
    }
    return ret;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        BigNum a(num1), b(num2);
        return (a * b).toString();
    }
};
