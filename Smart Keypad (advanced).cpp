#include <iostream>
#include<string>
#include<vector>
using namespace std;
#define pb push_back

vector<string> v;

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string keypad [] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void findIt(string s)
{
    for(auto x : searchIn)
    {
        int l = x.length();
        int idx = x.find(s);
        if( idx>= 0 && idx < l)
        {
            v.pb(x);
        }
    }
}

void smart_keypad(string inp, int i, char *out, int j)
{
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        string temp(out);
        findIt(temp);
        return;
    }
    int digit = inp[i] - '0';
    if(digit == 0 || digit == 1)
    {
        smart_keypad(inp, i + 1, out, j);
    }
    for(int k = 0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        smart_keypad(inp, i + 1, out, j + 1);
    }
}

int main() {
   string inp;
   cin >> inp;
   char out[100];
   smart_keypad(inp, 0, out, 0);
   for(auto x : v)
   {
       cout << x << endl;
   }
   return 0;
}
