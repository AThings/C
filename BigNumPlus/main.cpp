#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string a;
    string b;
    cin>>a>>b;

    string result = "";

    int aLong = a.length();//a�Ĺ�ע��
    int bLong = b.length();//b�Ĺ�ע��
    int shiwei =0;
    int gewei;
    stringstream sTmp;//char �����м�ֵ
    int iTmp;//int �����м�ֵ
    //cout<<(int)a[aLong-1]<<endl<<(int)b[bLong-1];

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
    /*
    result.insert(0,sTmp.str());
    sTmp.str("");*/
    if(shiwei)
    {
        sTmp<<shiwei;
        result.insert(0,sTmp.str());
        sTmp.str("");

    }
    cout<<result;
    return 0;
}
