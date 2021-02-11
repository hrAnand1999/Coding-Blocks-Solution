#include <iostream>
#include<string>
using namespace std;
bool is_Equal(string a, string b)
{
    if(a == b)
    return true;
    if(a.length() % 2 != 0)
    return false;
    int mid = a.length() / 2;
    string a1 = a.substr(0, mid);
    string a2 = a.substr(mid);
    string b1 = b.substr(0, mid);
    string b2 = b.substr(mid);
    if((is_Equal(a1, b1) && is_Equal(a2, b2)) || (is_Equal(a1, b2) && is_Equal(a2, b1)))
    return true;
    else
    return false;
}
int main() {
   int t;
   cin >> t;
   while(t--)
   {
       string a, b;
       cin >> a >> b;
       if(is_Equal(a, b))
       cout << "YES" << endl;
       else
       cout << "NO" << endl;
   }
   return 0;
}
