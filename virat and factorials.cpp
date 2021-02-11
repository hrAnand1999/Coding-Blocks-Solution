#include <iostream>
using namespace std;
#define m 1005

int multiply(int *a, int no, int size)
{
    int carry = 0;
    for(int i = 0; i < size; i++)
    {
        int prod = a[i] * no + carry;
        carry = prod / 10;
        a[i] = prod % 10;
    }
    while(carry)
    {
        a[size++] = carry % 10;
        carry /= 10;

    }
    return size;
}
void factorial(int n)
{
    int a[m];
    a[0] = 1;
    int size = 1;
    for(int i = 2; i <= n; i++)
    {
        size = multiply(a, i, size);
    }
    for(int i = size - 1; i >=0 ; i--)
    {
        cout << a[i];
    }
    cout << endl;
}
int main() {
   int n;
   cin >> n;
   factorial(n);
   return 0;
}
