#include <iostream>

using namespace std;
string hTostring(int h)
{
    string res;
    switch(h)
    {
        case 0:res = "zero";break;
        case 1:res = "one";break;
        case 2:res = "two";break;
        case 3:res = "three";break;
        case 4:res = "four";break;
        case 5:res = "five";break;
        case 6:res = "six";break;
        case 7:res = "seven";break;
        case 8:res = "eight";break;
        case 9:res = "nine";break;
        case 10:res = "ten";break;
        case 11:res = "eleven";break;
        case 12:res = "twelve";break;
        case 13:res = "thirteen";break;
        case 14:res = "fourteen";break;
        case 15:res = "fifteen";break;
        case 16:res = "sixteen";break;
        case 17:res = "seventeen";break;
        case 18:res = "eighteen";break;
        case 19:res = "nineteen";break;
        case 20:res = "twenty";break;
        case 30:res = "thirty";break;
        case 40:res = "forty";break;
        case 50:res = "fifty";break;
        default :res = "";
    }
    return res;
}
int main()
{
    int h,m;
    cin>>h>>m;
    int hg=-1;//h的个位
    int mg=-1;//m的个位
    if(h>20 && h<60 && h%10!=0)
    {
        hg = h%10;
        h = h-hg;
    }
    if(m==0)
    {
        cout<<hTostring(h);
        if(hg!=-1)
        {
            cout<<" "<<hTostring(hg);
        }
        cout<<" o'clock";
    }
    else
    {
        if(m>20 && m<60 && m%10!=0)
        {
            mg = m%10;
            m = m-mg;
        }
        cout<<hTostring(h);
        if(hg!=-1)
        {
            cout<<" "<<hTostring(hg);
        }
        cout<<" "<<hTostring(m);
        if(mg!=-1)
        {
            cout<<" "<<hTostring(mg);
        }
    }
    return 0;
}
