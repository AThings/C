#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int arrData[100][5];
    int arrPath[100][3];
    int pathArr[100][3];
    int Datanum = 0 ;
    int DataMin;
    int DataId = 0;
    int n;
    cin>>n;
    cin>>arrData[0][0]>>arrData[0][1]>>arrData[0][2];
    arrData[0][3] = arrData[0][0] > arrData[0][1] + arrData[0][2] ? arrData[0][0] : arrData[0][1]+arrData[0][2];
    arrData[0][4] = arrData[0][0] < arrData[0][1] + arrData[0][2] ? arrData[0][0] : arrData[0][1]+arrData[0][2];
    Datanum = arrData[0][3];
    DataId = 1;
    DataMin = arrData[0][4];
    for(int i=1;i<n;i++)
    {
        cin>>arrData[i][0]>>arrData[i][1]>>arrData[i][2];
        arrData[i][3] = arrData[i][0] > arrData[i][1] + arrData[i][2] ? arrData[i][0] : arrData[i][1]+arrData[i][2];
        arrData[i][4] = arrData[i][0] < arrData[i][1] + arrData[i][2] ? arrData[i][0] : arrData[i][1]+arrData[i][2];
        if(DataMin>arrData[i][4])
        {
            DataMin = arrData[i][4];
        }
        if (arrData[i][3]>Datanum)
        {
            Datanum = arrData[i][3];
            DataId = i+1;
        }
        else if(arrData[i][3] == Datanum && DataMin == arrData[i][4] )
        {
            Datanum = arrData[i][3];
            DataId = i+1;
        }

    }

    int tmp;
    int tmep;
    for(int i=0;i<n-1;i++)
    {
        cin>>tmp>>tmep;
        arrPath[i][0] = tmp<tmep?tmp:tmep;
        arrPath[i][1] = tmp>tmep?tmp:tmep;

    }

    int id = 0;
    for(int i=0;i<n-1;i++)
    {
        id = i;
        tmp = arrPath[i][0];
        tmep = arrPath[i][1];

        for(int j=i+1;j<n-1;j++)
        {
             if(tmp>arrPath[j][0])
            {
                tmp = arrPath[j][0];
                tmep = arrPath[j][1];
                id = j;
            }

        }
        arrPath[id][0] = arrPath[i][0];
        arrPath[id][1] = arrPath[i][1];
        arrPath[i][0] = tmp;
        arrPath[i][1] = tmep;


    }
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arrPath[i][0]==arrPath[j][0])
            {
                a=arrData[ arrPath[i][1]-1 ][3]-arrData[ arrPath[i][1]-1 ][4];
                b=arrData[ arrPath[j][1]-1 ][3]-arrData[ arrPath[j][1]-1 ][4];
                cout<<"a "<<a<<" b "<<b<<endl;
                if(a<b)
                {
                    a = arrPath[i][0];
                    b = arrPath[i][1];
                    arrPath[i][0] = arrPath[j][0];
                    arrPath[i][1] = arrPath[j][1];
                    arrPath[j][0] = a;
                    arrPath[j][1] = b;
                }
            }
        }
    }

    cout<<endl;
        for(int i=0;i<n-1;i++)
        {
            cout<<arrPath[i][0]<<" "<<arrPath[i][1]<<endl;
        }
        cout<<endl;

    int schaludian[n] ;
    int chaluNum = 0;
    schaludian[0] = DataId;
    chaluNum++;
    int shangyidian = -1;
    for(int i=0;i<n-1;i++)
    {
        pathArr[i][1] = arrPath[i][0];
        pathArr[i][0] = arrPath[i][1];
        pathArr[i][2] = arrPath[i][2] = 0;

        if(shangyidian == arrPath[i][0])
        {
            schaludian[chaluNum] = shangyidian;
            chaluNum++;
        }
        shangyidian = arrPath[i][0];
    }

    cout<<"-----------------------"<<endl;
    for(int i=0;i<chaluNum;i++)
    {
        cout<<schaludian[i]<<" ";
    }
    cout<<endl;
    cout<<"-----------------------"<<endl;

    int spath[n];
    int spathNum = 0;
    string path;
    spath[spathNum] = DataId;
    spathNum++;
    for(int i=0;i<chaluNum;i++)
    {
        DataId = schaludian[i] ;
        for(int j=0;j<n-1;j++)
        {

            for(int k=0;k<n-1;k++)
            {
                if( arrPath[k][0]==DataId && arrPath[k][2]!=1)
                {
                    arrPath[k][2]=1;
                    pathArr[k][2]=1;
                    DataId = arrPath[k][1];
                    spath[spathNum] = DataId;
                    spathNum++;
                    break;
                }
                else if(pathArr[k][0]==DataId && pathArr[k][2]!=1)
                {
                    pathArr[k][2]=1;
                    arrPath[k][2]=1;
                    DataId = pathArr[k][1];
                    spath[spathNum] = DataId;
                    spathNum++;
                    break;
                }
            }
        }
    }

    cout<<"-----------------------"<<endl;
    for(int i=0;i<spathNum;i++)
    {
        cout<<spath[i]<<" ";
    }
    cout<<endl;
    cout<<"-----------------------"<<endl;

    int needNum = 0;
    int nowNum = 0;
    for(int i=0;i<spathNum;i++)
    {
        id = spath[i]-1;

        if(nowNum<arrData[id][3])
        {
            needNum=needNum+arrData[id][3]-nowNum;
            nowNum=nowNum+arrData[id][3]-nowNum;
        }
        nowNum = nowNum - arrData[id][1]-arrData[id][2];
        cout<<"id"<<id<<"needNUm="<<needNum<<" nowNum="<<nowNum<<endl;
    }

    cout<<needNum<<endl;

    return 0;
}
