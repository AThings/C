#include <iostream>

using namespace std;

int main()
{
    int arrData[100][3];
    int arrPath[100][2];
    int tmp=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arrData[i][0]>>arrData[i][1]>>arrData[i][2];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>arrPath[i][0]>>arrPath[i][1];
    }
    for(int i=0;i<n;i++)
    {
        tmp=tmp+arrData[i][1]+arrData[i][2];
    }
    cout<<tmp<<endl;
    return 0;
}
