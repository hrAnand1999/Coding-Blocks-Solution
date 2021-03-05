#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int> graph[N];
int tin[N], tout[N], timer;
void euler_tour1(int curr, int parent)
{
     cout << curr << " ";
     tin[curr] = timer++;
    for(auto x : graph[curr])
    {
        if(x != parent)
        {
            euler_tour1(x, curr);
            cout << curr << " ";
            tout[curr] = timer++;
        }
        else
        {
            tout[curr] = tin[curr];
        }
    }
    
}
void euler_tour2(int curr, int parent)
{
     cout << curr << " ";
     tin[curr] = timer++;
    for(auto x : graph[curr])
    {
        if(x != parent)
        {
            euler_tour2(x, curr);
        }
    }
    tout[curr] = timer++;
    cout << curr << " ";
    return;
    
}
void euler_tour3(int curr, int parent)
{
     cout << curr << " ";
     tin[curr] = ++timer;
    for(auto x : graph[curr])
    {
        if(x != parent)
        {
            euler_tour3(x, curr);
        }
    }
    tout[curr] = timer;
   
    return;
    
}

// whether x is ancestor of y or not
bool ancestor(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    timer = 0;
    //   euler_tour1(1, 0);    init, timer = 1 
    //   euler_tour2(1, 0);    init, timer = 1
     euler_tour3(1, 0);        //init, timer = 0
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
          cout << i  << " " << tin[i] << " " << tout[i] << "\n";
    }
    if(ancestor(3, 2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
