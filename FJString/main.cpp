#include <iostream>

using namespace std;

string res(int n,string english)
{
    if(n==1)
    {
        return english.substr(n-1,1);
    }
    return ""+res(n-1,english)+english.substr(n-1,1)+res(n-1,english);
}
int main()
{
    int n;
    cin>>n;
    string english = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<res(n,english);
    return 0;
}
