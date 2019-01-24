#include <iostream>
#include <string>
using namespace std;

void iPrintJ(int i,int j)
{
    if(i>j)
    {
        return;
    }
    cout<<i<<endl;
    iPrintJ(i+1,j);
}

string re(string src,int end)
{
    if(end==0)
    {
        return src.substr(end,1);
    }
    return src[end]+re(src,end-1);
}
void insertSort(int arr[],int n)
{
    if(n==1)
    {
        return;
    }

    insertSort(arr,n-1);

    int x = arr[n-1];
    int index = n-1;
    while(index>0 && x<arr[index-1])
    {
        arr[index] = arr[index-1];
        index--;
    }
    arr[index] = x;
}

int quQiu(int n , int m)
{
    if(n<m) return 0;
    if(n==m) return 1;
    if(m==0) return 1;
    return quQiu(n-1,m-1)+quQiu(n-1,m);
}
int quanpailie(int arr[],int k,int n)
{
    if(k==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=k;i<n;i++)
    {
        {
           int t = arr[k];arr[k] = arr[i];arr[i] = t;
        }
        quanpailie(arr,k+1,n);
        {
           int t = arr[k];arr[k] = arr[i];arr[i] = t;
        }
    }
}
int main()
{
    /*
    iPrintJ(2,5);
    int arr[7] = {6,4,7,2,1,6,7};
    cout<<"___________________________\n";
    insertSort(arr,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"___________________________\n";
    cout<<re("labcde",4)<<endl;
    */
    //cout<<quQiu(10,3);
    int arr[5] = {1,2,3,4,5};
    quanpailie(arr,0,5);
    return 0;
}
