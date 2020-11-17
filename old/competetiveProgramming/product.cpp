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
  //expected size of the multipication output is always
  //length of the largest digit * 2 +1
  //10^4*10^4 == 10 ^(4+4) or 10^(4*2)
  int output[a.length() * 2 + 1] = {0};

  /**
    99
    99
    ---
    891   --->          output[2]output[1]output[0]
   891x   ---> output[3]output[2]output[1] x
   
   -----
   9801
   
    **/
  //X variable is literally the x as shown in the previous comment block where 99 * 99 is done

  for (int i = b.length() - 1; i >= 0; --i)
  {
    int j;
    int p = 0;
    for (j = a.length() - 1; j >= 0; --j)
    {
      //conversion from char to int = char-'0'

      int product = (a[i] - '0') * (b[j] - '0') + carry;
      //find carry only if product + previous value present in output  is greater than 10
      carry = output[x + p] + product > 10 ? (output[x + p] + product) / 10 : 0;
      //same for the output because each block can't have any number greater than 10 else it needs to be carried
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
  //this is one trick to find the size of array
  //&output gets the topmost pointer that is pointing to our array
  // whose width is equals to size of array
  /**
     * output       |
     * [0]          | &output[0] + 1   
     * [1]          |
     * [2]          | Width
     * [3]          |
     * [4]          |
     * [5]          |
     * &output + 1
     * **/
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
