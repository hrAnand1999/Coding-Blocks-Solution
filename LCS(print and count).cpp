#include <bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001][1001];
int LCS(string a, string b)
{
    int n = a.length();
    int m = b.length();
    
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i -1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}
string printLCS(string a, string b)
{
       int n = a.length();
       int m = b.length();
       string res;
       int i = n, j = m;
       while(i >= 0 && j >= 0)
       {
           if(dp[i -1][j] == dp[i][j - 1])
           {
               if(dp[i][j] != dp[i - 1][j])
               {
                   res += a[i - 1];
                   i--;
                   j--;
               }
               else{
                   i--;
               }
           }
           else 
           {
               if(dp[i][j] == dp[i - 1][j])
               {
                   i--;
               }
               else{
                   j--;
               }
           }
       }
       reverse(res.begin(), res.end());
       return res;
}
int main() {
    string a, b;
    cin >> a >> b;
    int len = LCS(a, b);
    string res = printLCS(a, b);
    cout << res << endl;
}
