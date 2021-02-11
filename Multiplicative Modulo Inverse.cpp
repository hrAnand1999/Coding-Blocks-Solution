#include <iostream>
using namespace std;
#define mod 1000000007
typedef pair<int, int> p;
//first --> y     second --> x
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}
p extendEuclid(int a, int b)
{
    p var;
    if(b == 0)
    {
        var.first = 0;
        var.second = 1;
        return var;
    }
    p temp = extendEuclid(b, a % b);
    var.second = temp.first;
    var.first = temp.second - (a / b) * temp.first;
    return var;
}
int inverseMultipicative(int a)
{
    if(GCD(a, mod) == 1)
    {
        p var = extendEuclid(a, mod);
        return (var.second + mod) % mod;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    cout << inverseMultipicative(n) << endl;
    
   return 0;
}
