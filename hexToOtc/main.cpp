#include <iostream>
#include <string>
using namespace std;

int main()
{
    string hex,otc,bin;
    string temp;
    int buling;
    int n;
    cin>>n;
    for(int k=0; k<n; k++)
        {
            otc="";
            bin="";
            cin>>hex;
            buling = (hex.length()*4)%3;
            for(int i=0; i<3-buling; i++)
            {
                bin.append("0");
            }
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
            for(int i=0; i<int(bin.length()); i+=3)
            {
                temp=bin.substr(i,3);
                if(temp=="000")
                {
                    temp="0";
                }
                else if(temp=="001")
                {
                    temp="1";
                }
                else if(temp=="010")
                {
                    temp="2";
                }
                else if(temp=="011")
                {
                    temp="3";
                }
                else if(temp=="100")
                {
                    temp="4";
                }
                else if(temp=="101")
                {
                    temp="5";
                }
                else if(temp=="110")
                {
                    temp="6";
                }
                else if(temp=="111")
                {
                    temp="7";
                }
                otc.append(temp);
            }
            bool flag = false;
            for(int i=0; i<otc.length(); i++)
            {
                //cout<<"otci="<<(otc[i]!=0)<<"\n";
                if(otc[i]!='0' && !flag)
                {
                    //cout<<"ok+"<<i<<"\n";
                    flag=true;
                }
                if(flag)
                {
                    cout<<otc[i];
                }
            }
            cout<<"\n";
        }
    return 0;
}
