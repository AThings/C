#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <int,int> mapNum;
    int num;
    cin>>num;
    int temp;//���е�ÿ����
    for(int i=1;i<=num;i++) //����hash��
    {
        cin>>temp;
        if(mapNum.find(temp) == mapNum.end())
        {
            mapNum[temp] = i;
        }
    }
    int findNum;
    cin>>findNum;
    if(mapNum.find(findNum) != mapNum.end())
    cout<<mapNum.find(findNum)->second;
    else
    cout<<-1;
    return 0;
}
