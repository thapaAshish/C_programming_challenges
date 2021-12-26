//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    ifstream mf;
    mf.open("warEagle.txt");
    std::string myText;

    int uniqueEagle[100] = {0};
    int warEagle = 0;
    while (getline(mf, myText))
    {
        myText = "0" + myText + "0";

        for (int i = 1; i < myText.length() - 1; i++)
        {
            if (uniqueEagle[i] == 0 and uniqueEagle[i - 1] == 0 and uniqueEagle[i + 1] == 0 and myText[i] == '1')
            {
                uniqueEagle[i] = 1;
                warEagle++;
            }
            if (myText[i] == '1')
            {
                uniqueEagle[i] = 1;
            }
        }

        int i = 0;
        for (char x : myText)
        {
            uniqueEagle[i++] = x - '0';
        }
    }
    cout << warEagle << endl;
    mf.close();
}
