#include <iostream>

using namespace std;

int main()
{
    string str = "00000";
    char tmp ;
    int num;//��λ
    int index; //��ע��


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
        while(num == 1 && index>=0);//�������ϼ���ִ��ѭ��

    }
    return 0;
}
