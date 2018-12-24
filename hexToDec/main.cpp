#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string hex,bin;
    long long dec = 0;
    string temp;
    bin="";
    cin>>hex;
    for(int i=0; i<int(hex.length()); i++)
    {
        switch(hex[i])
        {
        case '0':
            temp="0000";
            break;
        case '1':
            temp="0001";
            break;
        case '2':
            temp="0010";
            break;
        case '3':
            temp="0011";
            break;
        case '4':
            temp="0100";
            break;
        case '5':
            temp="0101";
            break;
        case '6':
            temp="0110";
            break;
        case '7':
            temp="0111";
            break;
        case '8':
            temp="1000";
            break;
        case '9':
            temp="1001";
            break;
        case 'A':
            temp="1010";
            break;
        case 'B':
            temp="1011";
            break;
        case 'C':
            temp="1100";
            break;
        case 'D':
            temp="1101";
            break;
        case 'E':
            temp="1110";
            break;
        case 'F':
            temp="1111";
            break;
        }
        bin.append(temp);
    }
    int length = (int)(bin.length());
    for(int i=0; i<length; i++)
    {
        long long iTonum = (long long)(((int)bin[length-i-1]%48)*pow(2,i));
        dec+=iTonum;
    }
    cout<<dec<<endl;
    return 0;
}
