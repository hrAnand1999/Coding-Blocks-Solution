#include <bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define mod 1000000007
#define ll long long int
ll dp[100002];
ll last_idx[26];
ll distict_subs(string s)
{
      memset(dp, 0, sizeof(dp));
      memset(last_idx, -1, sizeof(last_idx));
      dp[0] = 1;
      int n = s.length();
      for(int i = 1; i <= n; i++ )
      {
          dp[i] = (2 * dp[i -1]) % mod;
        //   check for repeating
        if(last_idx[s[i - 1] - 'A'] != -1)
        {
            dp[i] = (dp[i] - dp[last_idx[s[i - 1] - 'A']] + mod) % mod;
        }
        last_idx[s[i - 1] - 'A'] = i - 1;
      }
      return dp[n];
}
int main() {
    int t;
    cin >> t;
    vector<string> arr(t);
    for(int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < t; i++)
    {
        cout << distict_subs(arr[i]) << endl;
    }
    return 0;
}
