#include <iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
void gen_code(string inp, int i,char* out, int j)
{
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        //cout << out << endl;
        string temp(out);
        v.push_back(temp);
        return;
    }
    int digit = inp[i] - '0';
    if(digit == 0)
    {
        gen_code(inp, i + 1, out, j);
    }
    char ch = 'a' - 1 + digit;
    out[j] = ch;
    gen_code(inp, i + 1, out, j + 1);
    if(inp[i + 1] != '\0')
    {
        int second_digit = inp[i + 1] - '0';
        int no = digit * 10 + second_digit;
        if(no <27)
        {
            ch = 'a' - 1 + no;
            out[j] = ch;
            gen_code(inp, i + 2, out, j + 1);
        }
    }
}
int main() {
    string inp;
    cin >> inp;
    char out[1000];
    gen_code(inp, 0, out, 0);
    cout << "[";
    int s = v.size();
    int cnt = 0;
    for(auto x : v)
    {
        cout << x ;
        if(cnt < s - 1)
        {
            cout << ", ";
            cnt++;
        }
    }
    cout << "]";
    return 0;
}
