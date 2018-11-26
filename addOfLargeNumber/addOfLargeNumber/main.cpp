#include <iostream>

using namespace std;

int main()
{
    string a,b;
    int arr[1001];
    cin>>a>>b;
    size_t lena=a.length();
    size_t lenb=b.length();
    int max,min;
    int tot;//结果
    int xiao;//个位
    int temp=0;//十位
    int k=0;
    lena>lenb ? max=lena,min=lenb: min=lena,max=lenb;

    for(int i=lena-1,j=lenb-1;; i--,j--,k++)
    {
        if(i<0 || j<0)
        break;
        //cout<<"i="<<i<<"\n";
        tot=(a[i]+b[j])%48+temp;
        //cout<<"a[i]="<<a[i]<<" b[i]="<<b[i]<<"\n";
        xiao=tot%10;
        temp=tot/10;
        arr[k]=xiao;
        //cout<<"arr="<<arr[i]<<" xiao="<<xiao<<"temp"<<temp<<"\n";
    }

    if(lenb>lena)
    {
        for(int i=0;i<max-min;i++,k++)
        {
            tot=(b[i]+0)%48+temp;
            xiao=tot%10;
            temp=tot/10;
            arr[k]=xiao;
        }
    }
    else if(lenb<lena)
    {
        for(int i=0;i<max-min;i++,k++)
        {
            tot=(a[i]+0)%48+temp;
            xiao=tot%10;
            temp=tot/10;
            arr[k]=xiao;
        }
    }

    if(temp!=0)
    {
        arr[k]=temp;
        k++;
    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<arr[i];
    }

    return 0;
}
