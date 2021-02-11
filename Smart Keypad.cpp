#include <iostream>
#include<string>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void smart_keypad(string inp, int i, char *out, int j)
{
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    int digit = inp[i] - '0';
    for(int k = 0; table[digit][k] != '\0'; k++)
    {
        out[j] = table[digit][k];
        smart_keypad(inp, i + 1, out, j + 1);
    }
}
int main() {
   string inp;
   cin >> inp;
   char out[100];
   smart_keypad(inp, 0, out, 0);
   return 0;

}
