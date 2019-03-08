#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;//Ð¾Æ¬Êý
    int a[20][20];
    int flag[20] ;//¼ÇÂ¼ 0 1 Öµ
    memset(flag,0,sizeof(flag));
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            if(i!=j && a[i][j] == 1)
            {
                flag[j]++;
            }

        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<"="<<flag[i]<<" ";
        if(flag[i]>=n/2)
        {
            cout<<i+1<<" ";
        }
    }

    return 0;
}
