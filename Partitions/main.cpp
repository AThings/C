#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 1;
    while(true)
    {
        int w=0,h=0;//打印时，h不变，w实际长度为2*w+1
        string rec="";
        string temp="";
        string resultone="";
        string resulttwo="";
        string one="";
        string two="";

        getline(cin,temp);
        w=(int)temp[0]%48,h=(int)temp[2]%48;
        rec = temp.substr(3,(h+1)*(4*w+3));
        temp = temp.erase(0,(h+1)*(4*w+3)+3);

        for(int i=0;i<h+1;i++)
        {
            one=rec.substr(i*(4*w+3),2*w+1);
            two=rec.substr(i*(4*w+3)+2*w+2,2*w+1);
            cout<<"1="<<one<<endl;
            cout<<"2="<<two<<endl;
            for(int j=0;j<2*w+1;j++)
            {
                if(one[j]==two[j])
                {
                    resultone.append(one.substr(j,1));
                    resulttwo.append(one.substr(j,1));
                }
                else if(j%2==1)
                {
                    resultone.append("|");
                    resulttwo.append(" ");
                }
                else if(j%2==0)
                {
                    resultone.append("_");
                    resulttwo.append(" ");
                }
            }

        }
        for(int i=1;i<h;i++)
        {
            two=resulttwo.substr(i*(2*w+1),2*w-1);
            for(int j=1;j<2*w-1;j+=2)
            {
                if(two[j]!=two[j+2])
                {

                    for(int k=1;k<2*w;k+=2)
                    {
                        resulttwo[k]=" ";
                    }
                }
                if(two[j]!=resulttwo[i*(2*w+1)])
            }
        }
        if(temp == "0 0")
        {
            break;
        }
    }
    return 0;
}
