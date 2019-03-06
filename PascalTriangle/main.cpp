#include <iostream>
#include <sstream>
using namespace std;
/*
int PT(int m,int n)//求杨辉三角第m层第n个
{
    if(n==1)
    {
        return 1;
    }
    if(m==n)
    {
        return 1;
    }
    return PT(m-1,n)+PT(m-1,n-1);
}*/
int main()
{
    int level;
    cin>>level;
    int pt[34][34];
    for(int i=0 ; i<level ; i++)//遍历1~level层
    {
        for(int j=0;j<=i;j++)//遍历每一行
        {
            if(j==0 || j==i)
            {
                pt[i][j] = 1;
            }
            else
            {
                pt[i][j] = pt[i-1][j] + pt[i-1][j-1];
            }
        }
    }

    for(int i=0;i<level;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<pt[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
