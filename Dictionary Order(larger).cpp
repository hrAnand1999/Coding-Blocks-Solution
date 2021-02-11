#include <iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
set<string> s;
void fun(string inp)
{
    string check = inp;
    string temp = inp;
    do
    {
         if(inp > check)
         {
             s.insert(inp);
         }
         next_permutation(inp.begin(), inp.end());
    }while(temp != inp);
}
int main() {
    string inp;
    cin >> inp;
    fun(inp);
    for(auto x : s)
    {
        cout << x << endl;
    }
    return 0;
}
