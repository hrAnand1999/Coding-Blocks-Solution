#include <bits/stdc++.h>
#include<vector>
using namespace std;
int dp[101][101][2];
int bit_cnt(int n, int k, int first)
{
    /*if(n == k)
       return dp[n][k][first] = 1;*/
    if(n == 0)
       return dp[n][k][first] = 0;
    if(n == 1)
    {
        if(k == 0)
           return dp[n][k][first] = 1;
        else 
            return dp[n][k][first] = 0;
    }
    if(dp[n][k][first] != -1)
       return dp[n][k][first];
    int next = -1;
    if(first == 1)
    {
        next = bit_cnt(n - 1, k - 1, 1) + bit_cnt(n - 1, k , 0);
    }
    else
    {
        next = bit_cnt(n - 1, k, 0) + bit_cnt(n - 1, k, 1);
    }
    return dp[n][k][first] = next;
}
int main() {
    int t;
    cin >> t;
    int idx, n, k;
    vector<vector<int>> arr(t, vector<int>(3));
    for(int i = 0; i < t; i++)
    {
          cin >> idx >> n >> k;
          arr[i] = {idx, n, k};
    }
    /*for(auto x : arr)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }*/
    for(int i = 0; i < t; i++)
    {
        int idx = arr[i][0];
        int n = arr[i][1];
        int k = arr[i][2];
        if(k > n)
        {
            cout << 0 << endl;
        }
        else if(n == k)
        {
            cout << 1 << endl;
        }
        else{
            memset(dp, -1, sizeof(dp));
            int x = bit_cnt(n, k, 0);
            int y = bit_cnt(n, k, 1);
            cout << idx << " " << x + y << endl;
        }
        
    }
}
