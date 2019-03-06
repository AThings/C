#include <iostream>

using namespace std;

int main()
{
    int length;
    cin>>length;
    int max,min,sum;
    cin>>max;
    min = max;
    sum = min;
    int tmp;
    for(int i=1;i<length;i++)
    {
        cin>>tmp;
        if(max<tmp)
        {
            max = tmp;
        }
        if(min>tmp)
        {
            min = tmp;
        }
        sum+=tmp;
    }
    cout<<max<<endl<<min<<endl<<sum;
    return 0;
}
