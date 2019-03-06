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
string plusMlut(string a,string b)
{
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
    return res;
}

int strCompare(string a,string b)
{
    int aLong = a.length();
    int bLong = b.length();

    int aNum = 0;//a关注点
    int bNum = 0;//b关注点
    int flag = -1;//当aLong=blong记录大小的变量，1为a长，0为a短
    if(aLong == bLong)
    {
        while(aNum < aLong)//从高位开始比
        {
            if(a[aNum] > b[bNum])
            {
                flag = 1;
                break;
            }
            else if(a[aNum] < b[bNum])
            {
                flag = 0;
                break;
            }
            aNum++;
            bNum++;
        }
    }
    if( (aLong > bLong) || flag == 1)
    {   //a比b大
        return 1;
    }
    else if( (aLong < bLong) || flag == 0)
    {   //a比b小
        return 0;
    }
    if(flag == -1)
    {
        return -1;
    }
}

int main()
{

    string a,m,p,q,r,s;//每次加的值，每次乘的值，pq作用域，rs值域
    cin>>a>>m>>p>>q>>r>>s;
    string res;//存结果字符串

    string pTmp=p;
    string qTmp=q;
    int num=0;//长度

    while(true)//先得到m个数
    {
        pTmp = plusMlut(pTmp,m);
        qTmp = plusMlut(qTmp,m);
        if(strCompare(pTmp,s) == 1 || strCompare(qTmp,s) == 1)
        {
            break;
        }
        else
        {
            res.append("m");
            num++;
        }

    }
    cout<<res<<endl<<num;
    return 0;
}
