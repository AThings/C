#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin>>str;
    reverse(str.begin(),str.end());
    int flag = 0;//Êı×ÖµÈ¼¶
    string tmp;
    while(str.length()>4)
    {
        tmp = str.substr(0,4);
        str.erase(0,4);
        reverse(tmp.begin(),tmp.end());
        //cout<<tmp<<endl;
        for(int i=0;i<tmp.length();i++)
        {
            switch(temp[i])
            {

            }
        }
    }
    return 0;
}
