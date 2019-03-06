#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n; //要求的阶乘
    cin>>n;
    string result = "1";
    char cTmp;
    int iTmp;
    int shiwei;
    int gewei;
    bool jinwei;//是否进位
    stringstream tmp;


    for(int i=2;i<=n;i++)
    {
        shiwei = 0;
        for(int j=result.length()-1;j>=0;j--)
        {
            cTmp = result[j];
            iTmp = ((int)cTmp%48)*i+shiwei;
            //cout<<"iTmp="<<iTmp<<endl;
            if(iTmp>=10)
            {
                jinwei = true;
            }
            else
            {
                jinwei = false;
            }

            gewei = iTmp%10;
            cTmp = (char)( gewei + 48);
            //cout<<"   cTmp"<<cTmp<<endl;
            shiwei = iTmp/10;
            result[j] = cTmp;
            //cout<<"j="<<j<<endl;
        }
        if(jinwei)
        {
            //cout<<"   res="<<result<<endl;
            tmp<<shiwei;
            result.insert(0,tmp.str());
            tmp.str("");
            //cout<<"   res="<<result<<endl;
        }
        //cout<<"res="<<result<<endl<<endl;
        //cout<<"i="<<i<<endl;
    }
    cout<<result;
    return 0;
}
