#include <bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> gr[N];
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{
      int i = 0, j = 0;
      for(int r = 0; r < n; r++)
      {
          for(int c = 0; c < n; c++)
          {
              if(r != p && c != q)
              {
                  temp[i][j++] = mat[r][c];
                  if(j == n - 1)
                  {
                      j = 0;
                      i++;
                  }
              }
          }
      }
}
int determinant(int mat[N][N], int n)
{
    int D = 0;
    
    if(n == 1)
    return mat[0][0];

    int temp[N][N];
    int sign = 1;
    for(int f = 0; f < n; f++)
    {
        getCofactor(mat, temp, 0, f, n);
        D += (sign * mat[0][f] * determinant(temp, n - 1));
        sign = -sign;
    }
    return D;
}
int main() {
   int n, m;
   cin >> n >> m;
   int x, y;
   while(m--)
   {
       cin >> x >> y;
       gr[x].push_back(y);
       gr[y].push_back(x);
   }
//    now we have to calculate degree of each node
   vector<int> degree(n + 1, 0);
   for(int i = 1; i <= n; i++)
   {
       degree[i] = gr[i].size();
   }
//    Now create adjacency matrix
  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++)
  {
      for(auto child : gr[i])
      {
          adj[i][child] = 1;
      }
  }
//   place degree at diagonal elements
  for(int i = 1; i <= n; i++)
  {
      adj[i][i] = degree[i];
  }
// Replace al the non diagonal 1's with -1;
  for(int i = 1; i <= n; i++)
  {
      for(int j = 1; j <= n; j++)
      {
          if(i != j && adj[i][j] == 1)
          {
              adj[i][j] = -1;
          }
      }
  }
// time to calculate cofactor of 1st element
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
        cout << adj[i][j] << " ";
    }
    cout << endl;
}
int mat[N][N];
for(int i = 2; i <= n; i++)
{
    for(int j = 2; j <= n; j++)
    {
        mat[i - 2][j - 2] = adj[i][j];
    }
}
for(int i = 0; i < n - 1; i++)
{
    for(int j = 0; j < n - 1; j++)
    {
        cout << mat[i][j] << " ";
    }
    cout << endl;
}
    cout << determinant(mat, n -1 );
return 0;
}
