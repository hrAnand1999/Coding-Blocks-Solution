#include <iostream>
using namespace std;
int opt_game(int *a, int i, int j)
{
    
    if(i + 1 == j)
    {
        return max(a[i], a[j]);
    }
    int op1 = a[i] + min(opt_game(a, i + 2, j), opt_game(a, i + 1, j - 1));
    int op2 = a[j] + min(opt_game(a, i + 1, j - 1), opt_game(a, i, j - 2));
    return max(op1, op2);
}
int main() {
   int n;
   cin >> n;
   int a[n];
   for(int i = 0; i < n; i++)
   {
       cin >> a[i];
   }
   cout << opt_game(a, 0, n - 1);
   return 0;
}
