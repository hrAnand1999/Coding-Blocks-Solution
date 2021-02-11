#include <iostream>
#include<set>
#include<string>
using namespace std;
void permute(string t, int i, set<string> & s)
{
    if(t[i] == '\0')
    {
        s.insert(t);
        return;
    }
    for(int j = i; t[j] != '\0'; j++)
    {
        swap(t[i], t[j]);
        permute(t, i + 1, s);
        swap(t[i], t[j]);
    }
    return;
}
int main() {
    string t;
    cin >> t;
    set<string> s;
    permute(t, 0, s);
    for(auto x : s)
    {
        cout << x << endl;
    }
    return 0;
}
