#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Addition(vector<int> S, vector<int> D)
{
    reverse(S.begin(), S.end());
    reverse(D.begin(), D.end());

    vector<int> ans;
    int i = 0, j = 0;
    int carry = 0;
    while(i < S.size() && j < D.size()){
        int val = S[i] + D[j] + carry;
        carry = val / 10;
        ans.push_back(val % 10);
        i++;
        j++;
    }
    for(; i < S.size(); i++)
    {
        int val = S[i] + carry;
        carry = val / 10;
        ans.push_back(val % 10);
    }
    for(; j < D.size(); j++){
        int val = D[j] + carry;
        carry = val / 10;
        ans.push_back(val % 10);
    }
    while(carry)
    {
        ans.push_back(carry % 10);
        carry /= 10;

    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> Divideby2(vector<int> add)
{
    vector<int> ans;
    int rem = 0;
    for(int i = 0; i < add.size(); i++){
        if(rem){
            add[i] = rem * 10 + add[i];
            rem = add[i] % 2;
            ans.push_back(add[i] / 2);
        }
        else{
            if(add[i] < 2){
                rem += add[i];
                ans.push_back(0);
            }
            else{
                rem = add[i] % 2;
                ans.push_back(add[i] / 2);
            }
        }
    }
    
    //to avoid leading zeroes
    vector<int> arr;
    int  i = 0;
    while(ans[i] == 0) i++;
    for(; i < ans.size(); i++)
    {
        arr.push_back(ans[i]);
    }
    return arr;
}
vector<int> Minus(vector<int> x, vector<int> y){
    //Assuming x>=y
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    vector<int> ans;
    int len = y.size();
    for(int i = 0; i < len; i++)
    {
        if(x[i] < y[i]){
            x[i + 1]--;
            ans.push_back(10 + x[i] -y[i]);
        }
        else{
            ans.push_back(x[i] - y[i]);
        }
    }
    if(x.size() > len){
        for(int i = len; i < x.size(); i++){
            if(x[i] < 0){
                x[i + 1]--;
                ans.push_back(10 + x[i]);
            }
            else{
                ans.push_back(x[i]);
            }
        }
        
    }
    reverse(ans.begin(), ans.end());
        //to omit leading zeroes
        vector<int> arr;
        int i = 0;
        while(ans[i] == 0) i++;
        for(; i < ans.size(); i++)
        arr.push_back(ans[i]);
        return arr;
}
int main() {
    for(int t = 0; t < 10; t++)
    {
        string sum, diff;
        cin >> sum >> diff;
        
        
        vector<int> S, D, add, div, subtract;

        for(int i = 0; i < sum.length(); i++) S.push_back(sum[i] - '0');
        for(int i = 0; i < diff.length(); i++) D.push_back(diff[i] - '0');

        add = Addition(S, D);
        div = Divideby2(add);

        //Apple Klaudia have
        for(int i = 0; i < div.size(); i++)  cout << div[i];
        cout << endl;

        //Apple Natalia have
        subtract = Minus(div, D);
        if(subtract.size() == 0)
        cout << 0 << endl;
        else
        for(int i = 0; i < subtract.size(); i++) cout << subtract[i];
        cout << endl;
    }
    return 0;
}
