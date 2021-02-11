#include <iostream>
#include<iomanip>
using namespace std;
int main() {
   int t;
   cin >> t;
   while(t--)
   {
       double n;
       cin >> n;
       double res = 0;
       for(double i = 1; i <= n; i++)
       {
           res += (n  / i);
       }
       
       cout << fixed << setprecision(2) << res << endl;
   }
   return 0;
}
