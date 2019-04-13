#include <iostream>
#include <string.h>
using namespace std;
const int nMax = 102;
int guanxi[nMax][nMax];
int kaochang[nMax][nMax];
int renshu[nMax];
int main()
{
    int num;//学生人数
    cin>>num;
    int k;
    cin>>k;
    int a,b;
    memset(guanxi,-1,sizeof(guanxi));
    memset(kaochang,-1,sizeof(kaochang));
    memset(renshu,0,sizeof(renshu));
    while(k--)
    {
        cin>>a>>b;
        guanxi[b-1][a-1] = guanxi[a-1][b-1] = 1;
    }

    int jNum=1;//教室
    renshu[0]=1;
    kaochang[0][0]=0;
    int flag;
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            cout<<guanxi[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<num; i++)
    {

        for(int j=0; j<jNum; j++)
        {
            /*
            for(int i=0; i<num; i++)
            {
                for(int j=0; j<num; j++)
                {
                    cout<<kaochang[i][j]<<" ";
                }
                cout<<endl;
            }*/
            flag=0;
            for(int k=0; k<renshu[j]; k++)
            {
                if(guanxi[i][kaochang[j][k]]==1)
                {

                    flag=1;
                    break;
                }
            }

            if(flag==1 && j==jNum-1)
            {
                jNum++;
                kaochang[jNum-1][0]=i;
                renshu[jNum-1]++;
                //cout<<i<<" "<<j<<" "<<kaochang[jNum-1][0]<<"````\n";
                break;
            }
            else if(flag==0)
            {
                //cout<<renshu[j]<<endl<<endl;
                kaochang[j][renshu[j]]=i;
                renshu[j]++;
                //cout<<i<<" "<<j<<"~~~~~~~\n";
                break;
            }
        }
    }
    for(int i=0; i<jNum; i++)
    {
        for(int j=0; j<renshu[i]; j++)
        {
            cout<<kaochang[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<jNum;
    return 0;
}
