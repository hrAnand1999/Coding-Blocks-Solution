#include <iostream>
#include<vector>
using namespace std;
int main() {
    //enter the row upto which you want to print pascal traingle
    //0 based indexing
    int r;
    cin >> r;
    vector<vector<int>> v;
    v.reserve(r);
    v.push_back({1});
    v.push_back({1,1});
    for(int i = 2; i < r; i++){
        vector<int> temp;
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
            {
                 temp.push_back(1);
            }
            else{
                temp.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
        }
        v.push_back(temp);
    }
    for(int i = 0; i < r; i++)
    {
        for(auto x: v[i])
        cout << x << " ";
        cout << endl;
    }
}
