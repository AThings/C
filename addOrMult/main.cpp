#include <iostream>
#include <sstream>
using namespace std;


string plusAdd(string a,string b)
{
    string result = "";

    int aLong = a.length();//a�Ĺ�ע��
    int bLong = b.length();//b�Ĺ�ע��
    int shiwei =0;
    int gewei;
    stringstream sTmp;//char �����м�ֵ
    int iTmp;//int �����м�ֵ

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
    string res="0";//������
    string resTmp="";//����ÿһ��˷����м�ֵ

    int iTmp;//ÿһ�μ����ֵ
    int jinwei=0;//�����λ
    int gewei;//��λ
    int maxPin=maxLong;//maxLong��ע��
    stringstream sTmp;//intתstring

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
        //����resTmp��0�ĳ���
        for(int i=0;i<maxLong-maxPin;i++)
        {
            resTmp.insert(0,"0");
        }
        //ȡ���һλ��ת��������
        for(int i=0; i<minLong; i++)
        {
            iTmp = ( (int)maxStr[maxPin-1] % 48)*( (int)minStr[minLong-1-i] % 48)+jinwei;
            jinwei = iTmp/10;
            gewei = iTmp%10;
            sTmp<<gewei;
            resTmp.insert(0,sTmp.str());
            sTmp.str("");
        }
        //�������һλ�Ľ�λ����
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

    int aNum = 0;//a��ע��
    int bNum = 0;//b��ע��
    int flag = -1;//��aLong=blong��¼��С�ı�����1Ϊa����0Ϊa��
    if(aLong == bLong)
    {
        while(aNum < aLong)//�Ӹ�λ��ʼ��
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
    {   //a��b��
        return 1;
    }
    else if( (aLong < bLong) || flag == 0)
    {   //a��bС
        return 0;
    }
    if(flag == -1)
    {
        return -1;
    }
}

int main()
{

    string a,m,p,q,r,s;//ÿ�μӵ�ֵ��ÿ�γ˵�ֵ��pq������rsֵ��
    cin>>a>>m>>p>>q>>r>>s;
    string res;//�����ַ���

    string pTmp=p;
    string qTmp=q;
    int num=0;//����

    while(true)//�ȵõ�m����
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
