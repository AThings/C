#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string first="1";
    string second="1 1";
    stringstream temp;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<first<<endl;
        }
        else if(i==1)
        {
            cout<<second<<endl;
        }
        else
        {
            first=second;
            for(int j=0;j<2*i+1;j++)
            {
                if(j%2==1)
                {
                    temp<<" ";
                }
                else if(j==0 || j==2*i)
                {
                    temp<<"1";
                }
                else
                {
                    //cout<<2*n<<endl;
                    //cout<<"first[j]="<<first[j]<<" first[j-2]"<<first[j-2]<<endl;
                    temp<<(int)first[j]%48+(int)first[j-2]%48;
                }
            }
            second=temp.str();
            temp.str("");
            cout<<second<<endl;
        }
    }
    return 0;
}
