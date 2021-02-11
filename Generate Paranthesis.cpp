#include <iostream>
#include<string>
using namespace std;

void gen_par(int n, int i, int open, int close, char* out)
{
    if(i == 2*n)
    {
        out[i] = '\0';
        
        cout << out << endl;
        return;
    }
    if(close < open)
    {
       out[i] = ')';
        gen_par(n, i + 1, open, close + 1, out);
    }
    if(open < n)
    {
       out[i] = '(';
        gen_par(n, i + 1, open + 1, close, out);
    }
   
}
int main() {
   int n;
   cin >> n;
   char out[1000];
   int open = 0, close = 0;
   gen_par(n, 0, open, close, out);
   
   return 0;
}
