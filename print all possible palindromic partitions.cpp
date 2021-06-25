#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;
bool isPalindrome(string s)
{
    int n = s.length();
    if(n == 1)
    return true;
    int i = 0, j = n - 1;
    while(i < j)
    {
        if(s[i] != s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
void fun(string s, vector<string> res, int i)
{
    if(i >= s.length())
    {
        ans.push_back(res);
        return;
    }
    for(int j = i; j < s.length(); j++)
    {
        string temp = s.substr(i, j - i + 1);
        if(isPalindrome(temp))
        {
            res.push_back(temp);
            fun(s, res, j + 1);
            res.pop_back();
        }
    }
}
int main() {
    string s;
    cin >> s;
    vector<string> res;
    fun(s, res, 0);
    for(auto arr : ans)
    {
         for(auto str : arr)
         cout << str << "  ";
         cout << endl;
    }
    return 0;
}
