#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//if input is 12 and 12333 make it 00012 and 12333
void padString(std::string &a, std::string &b)
{
    if (a.length() > b.length())
    {
        b = std::string(a.length() - b.length(), '0') + b;
    }
    else
    {
        a = std::string(b.length() - a.length(), '0') + a;
    }
}

int main()
{
    std::string a, b;
    cin >> a;
    cin >> b;
    int carry = 0;
    padString(a, b);
    int x = 0;
    int output[a.length() * 2 + 1] = {0};
    for (int i = b.length() - 1; i >= 0; --i)
    {
        int j;
        int p = 0;
        for (j = a.length() - 1; j >= 0; --j)
        {
            int product = (a[i] - '0') * (b[j] - '0') + carry;
            carry = output[x + p] + product > 10 ? (output[x + p] + product) / 10 : 0;
            output[x + p] = output[x + p] + product > 10 ? (output[x + p] + product) % 10 : output[x + p] + product;
            p++;
        }
        output[x + p] = carry;
        carry = 0;
        x += 1;
    }
    bool zeroFlag{true};
    int len = *(&output + 1) - output;
    //cout << len << endl;
    for (int i = (*(&output + 1) - output) - 2; i >= 0; --i)
    {
        if (output[i] != 0)
        {
            zeroFlag = false;
        }
        if (!zeroFlag)
        {
            cout << output[i];
        }
    }
    cout << endl;
}
