#include <iostream>
#include <sstream>
using namespace std;
string An(int start,int end,int flag)
{
    if(start==end)
    {
        stringstream tmp;
        tmp<<"sin("<<start<<")";
        return tmp.str();
    }
    if(flag)
    {
       flag=0;
       stringstream tmp;
       tmp<<"sin("<<start<<"+"<<An(start+1,end,flag)<<")";
       return tmp.str();
    }
    else
    {
       flag=1;
       stringstream tmp;
       tmp<<"sin("<<start<<"-"<<An(start+1,end,flag)<<")";
       return tmp.str();
    }
}
string Sn(int start,int end)
{
    if(start==1)
    {
        stringstream tmp;
        tmp<<An(1,start,0)<<"+"<<end+1-start;
        return tmp.str();
    }

    stringstream tmp;
    tmp<<"("<<Sn(start-1,end)<<")"<<An(1,start,0)<<"+"<<end+1-start;
    return tmp.str();
}
int main()
{
    int n;
    cin>>n;
    cout<<An(1,n,0)<<endl;;
    cout<<Sn(n,n);
    return 0;
}
