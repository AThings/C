#include <iostream>

using namespace std;
//数组插入排序
void insertSort(int a[],int index,int willcha,int start)
{
        while(a[index-1]<=willcha && index >start)
        {
            a[index] = a[index-1];
            index--;
        }
        a[index] = willcha;/*
        cout<<"------------------------\n";
        for(int i=0;i<5;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"------------------------\n";*/
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(int i=1;i<n;i++) //从长度2开始排序
    {
        //i要插入的数字index
        insertSort(a,i,a[i],0);
    }/*
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    int result = 0;
    int minPlus;

    for(int i=n-1;i>0;i--)
    {
        minPlus = a[i]+a[i-1];
        result +=minPlus;
        a[i-1] = minPlus;
        insertSort(a,i-1,a[i-1],0);
/*
        for(int j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;

        cout<<"result="<<result<<endl;*/
    }
    cout<<result<<endl;
/*
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }*/
    return 0;
}
