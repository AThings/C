#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

struct node
{
    double x,y;
};
const int intMax = 999999;
const int Max = 20;

node nodeArr[Max];
long double lineArr[Max][Max];
long double D[Max][Max];
int main()
{
    int n;
    cin>>n;
    int maxPage;
    cin>>maxPage;
    for(int i=0;i<n;i++)
    {
        cin>>nodeArr[i].x>>nodeArr[i].y;
    }

    memset(lineArr,intMax,sizeof(lineArr));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            lineArr[i][j] = sqrt ( pow((nodeArr[i].x - nodeArr[j].x),2) + pow( (nodeArr[i].y-nodeArr[j].y) , 2)) ;
            if(lineArr[i][j]>maxPage/2)
            {
                lineArr[i][j] = intMax;
            }
            D[i][j] = D[j][i] = lineArr[j][i] = lineArr[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout.setf(ios::left);
            cout.width(10);
            cout<<lineArr[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(D[j][i]+D[i][k]<D[j][k] && D[j][i]+D[i][k]>=0)
                {
                    D[j][k] = D[j][i] + D[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout.setf(ios::left);
            cout.width(10);
            cout<<D[i][j];
        }
        cout<<endl;
    }

    D[0][n-1] = ceil(D[0][n-1]);
    if(D[0][n-1]==intMax)
    {
        cout<<"Impossible"<<endl;
    }
    else if(D[0][n-1]==1)
    {
        cout<<D[0][n-1]<<" unit of food"<<endl;
    }
    else
    {
        cout<<D[0][n-1]<<" units of food"<<endl;
    }
    return 0;
}
