#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    stringstream sPic ;
    for(int i=1;i<=m;i++)
    {
        sPic<<(char)(64+i);
    }
    string pic = sPic.str();
    char tmp ;
    cout<<pic<<endl;
    for(int i=1;i<n;i++) //i ¹Ø×¢µã
    {
        for (int j=0;j<m;j++)
        {
            tmp = pic[j];
            if(j<i)
            {
                tmp+=1;
                pic[j] = tmp;
            }
            else
            {
                tmp-=1;
                pic[j] = tmp;
            }
        }
        cout<<pic<<endl;
    }
    //cout<<pic;
    return 0;
}
