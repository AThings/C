#include <iostream>
#include <sstream>
using namespace std;
string five(int n){
    if(n == 1 || n>45)
    {
        return "";
    }
    else
    {
        int maxSum = n/2 < 18 ? n/2:18;
        int medNum;
        stringstream resultStr;
        for(int i=10;i<100;i++)
        {
            if(i/10+i%10>maxSum)
            {
                continue;
            }
            medNum = n-(i/10+i%10)*2;
            if(medNum>=10 || medNum<0)
            {
                continue;
            }
            else
            {
                resultStr<<i/10<<i%10<<medNum<<i%10<<i/10;
            }
        }
        return resultStr.str();
    }
}

string six(int n)
{
    if(n%2==1 || n==1)
    {
        return "";
    }
    else
    {
        int maxSun = n/2;
        int sumNum;
        stringstream res;
        for(int i=100;i<1000;i++)
        {
            sumNum = i/100+i%100/10+i%10;
            if(sumNum==maxSun)
            {
                res<<i/100<<i%100/10<<i%10<<i%10<<i%100/10<<i/100;
            }
            else
            {
                continue;
            }
        }
        return res.str();
    }
}
int main()
{
    int n;
    cin>>n;
    string sixFigures = "";
    string fiveFigures = "";
    fiveFigures=five(n);
    sixFigures=six(n);
    for(int i=0;i<fiveFigures.length()/5;i++)
    {
        cout<<fiveFigures.substr(i*5,5)<<endl;
    }
    for(int i=0;i<sixFigures.length()/6;i++)
    {
        cout<<sixFigures.substr(i*6,6)<<endl;
    }
}
