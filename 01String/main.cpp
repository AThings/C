#include <iostream>

using namespace std;

int main()
{
    string str = "00000";
    char tmp ;
    int num;//进位
    int index; //关注点


    while(true)
    {
        cout<<str<<endl;
        if(str == "11111")
        {
            break;
        }

        index = 4;
        num = 0;
        do
        {
            tmp = str[index]+1;
            if(tmp == '2')
            {
                tmp = '0';
                str[index] = tmp;
                num = 1;
            }
            else
            {
                str[index] = tmp;
                num = 0;
            }
            index--;
        }
        while(num == 1 && index>=0);//条件符合继续执行循环

    }
    return 0;
}
