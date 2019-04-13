#include <iostream>
#include <sstream>
using namespace std;
stringstream tmp;
int jinzhi = 10;
long long int god = 0;//基础值 (数值型)
string strGod;//基础值 (字符型型)
long long int yunshuan;//运算值
string stryunshuan;
int inFlag = 0;//是否可以输入基础值
int calFlag = -1;//运算flag 0 add 1 sub 2 mul 3 div 4 mod

long long int Atoi(string s,int radix)    //s是给定的radix进制字符串
{
	long long int ans=0;
	for(int i=0;i<s.length();i++)
	{
		char t=s[i];
		if(t>='0'&&t<='9') ans=ans*radix+(t-'0');
		else ans=ans*radix+(t-'A')+10;
	}
		return ans;
}

string hewToNow(long long int s,int radix) //10转到radix进制
{
    string res = "";
    string aaa = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int yushu;
    while(true)
    {
        yushu = s%radix;
        s /= radix;

        tmp<<aaa[yushu];
        res.insert(0,tmp.str());
        tmp.str("");

        if(s==0)
        {
            break;
        }
    }
    return res;
}
void NUM()
{
    if(inFlag)
    {
        cin>>strGod;
        god = Atoi(strGod,jinzhi);
        tmp<<god;
        strGod = tmp.str();
        tmp.str("");
        inFlag = 0;
    }
    else
    {
        cin>>stryunshuan;
        yunshuan = Atoi(stryunshuan,jinzhi);
        tmp<<yunshuan;
        stryunshuan = tmp.str();
        tmp.str("");

    }

    if(calFlag != -1)
    {

        //god = Atoi(strGod,10);
        //yunshuan = Atoi(stryunshuan,10);
        //cout<<"god="<<god<<"yunshuan="<<yunshuan<<endl;
        switch(calFlag)
        {
            case 0: god+=yunshuan;break;
            case 1: god-=yunshuan;break;
            case 2: god*=yunshuan;break;
            case 3: god/=yunshuan;break;
            case 4: god%=yunshuan;break;
        }
        //cout<<"god="<<god<<endl;
        tmp<<god;
        strGod = tmp.str();
        tmp.str("");
        calFlag = -1;
    }
}
void setjinzhi()
{
    cin>>jinzhi;
}
void runorder(string order)
{
    string mingling[9] = {"NUM","ADD","SUB","MUL","DIV","MOD","CHANGE","EQUAL","CLEAR"};
    int mlIndex = -1;
    for(int i=0;i<9;i++)
    {
        if(mingling[i] == order)
        {
            mlIndex = i;
        }
    }

    switch(mlIndex)
    {
        case 0: NUM();break;
        case 1: inFlag = 0 ,calFlag = 0;break;
        case 2: inFlag = 0 ,calFlag = 1;break;
        case 3: inFlag = 0 ,calFlag = 2;break;
        case 4: inFlag = 0 ,calFlag = 3;break;
        case 5: inFlag = 0 ,calFlag = 4;break;
        case 6: setjinzhi();break;
        case 7: cout<<hewToNow(god,jinzhi)<<endl;break;
        case 8: inFlag = 1 ,calFlag = -1;break;
    }
}
int main()
{
    int num;
    cin>>num;
    string order;


    while(num--)
    {
        cin>>order;
        runorder(order);
        //cout<<"strGod="<<strGod<<endl;
    }
    return 0;
}
