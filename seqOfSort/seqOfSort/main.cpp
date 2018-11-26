#include <iostream>

using namespace std;

int main()
{
    //test test
    int arr[200];
    int n;//数组长度
    int temp,big;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    for(int i=0; i<n; i++)
    {
        big =0;
        for(int j=0; j<n-i; j++)
        {

            if(arr[big]<arr[j])
            {
                big = j;
            }
        }
        //cout<<"big="<<arr[big]<<" arr[n-i-1]="<<arr[n-i-1]<<"\n";
        temp = arr[n-i-1];
        arr[n-i-1]=arr[big];
        arr[big]=temp;
        /*
        for(int j=0; j<n; j++)
        {
            cout<<arr[j];
        }
        cout<<"\n";*/
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}
