#include <iostream>
#include <sstream>
using namespace std;
string plusAdd(string a,string b)
{
    string result = "";

    int aLong = a.length();//a的关注点
    int bLong = b.length();//b的关注点
    int shiwei =0;
    int gewei;
    stringstream sTmp;//char 类型中间值
    int iTmp;//int 类型中间值

    while(true)
    {
        if(aLong==0 || bLong==0)
        {
            break;
        }
        iTmp = (int)a[aLong-1]%48 + (int)b[bLong-1]%48+shiwei;
        shiwei = iTmp/10;
        gewei = iTmp%10;
        sTmp<<gewei;
        result.insert(0,sTmp.str());
        sTmp.str("");

        aLong--;
        bLong--;
    }
    string shengyu = "";
    int syLong = 0;
    if(aLong !=0)
    {
        shengyu = a;
        syLong = aLong;
    }
    if(bLong !=0)
    {
        shengyu = b;
        syLong = bLong;
    }
    while(true)
    {
        if(shiwei == 0 || syLong == 0)
        {
            break;
        }
        iTmp = (int)shengyu[syLong-1]%48+shiwei;
        shiwei = iTmp/10;
        gewei = iTmp%10;
        sTmp<<gewei;
        result.insert(0,sTmp.str());
        sTmp.str("");

        syLong--;
    }
    result.insert(0,shengyu.substr(0,syLong));
    if(shiwei)
    {
        sTmp<<shiwei;
        result.insert(0,sTmp.str());
        sTmp.str("");

    }
    return result;
}
int main()
{
    string a,b;
    cin>>a>>b;

    int panduan = a.length()>b.length() ? 1:0;

    int maxLong = panduan?a.length():b.length();
    int minLong = panduan?b.length():a.length();

    string maxStr = panduan?a:b;
    string minStr = panduan?b:a;
    string res="0";//保存结果
    string resTmp="";//保存每一层乘法的中间值

    int iTmp;//每一次计算的值
    int jinwei=0;//处理进位
    int gewei;//个位
    int maxPin=maxLong;//maxLong关注点
    stringstream sTmp;//int转string

    while(true)
    {
        if(maxPin==0)
        {
            break;
        }
        if(minLong==0)
        {
            break;
        }
        //处理resTmp后0的长度
        for(int i=0;i<maxLong-maxPin;i++)
        {
            resTmp.insert(0,"0");
        }
        //取最后一位并转换成数字
        for(int i=0; i<minLong; i++)
        {
            iTmp = ( (int)maxStr[maxPin-1] % 48)*( (int)minStr[minLong-1-i] % 48)+jinwei;
            jinwei = iTmp/10;
            gewei = iTmp%10;
            sTmp<<gewei;
            resTmp.insert(0,sTmp.str());
            sTmp.str("");
        }
        //处理最后一位的进位问题
        if(jinwei!=0)
        {
          sTmp<<jinwei;
          resTmp.insert(0,sTmp.str());
          sTmp.str("");
          jinwei = 0;
        }

        res = plusAdd(resTmp,res);
        resTmp = "";
        maxPin--;
    }
    cout<<res;
    return 0;
}
