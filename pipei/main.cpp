#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int a [1000*1000];
int num [1000*1000];
int main()
{
    int n,k;
    cin>>n>>k;
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    sort(a,a+n);
    int res =0 ;
    for(int i=0;i<n;i++)
    {
        if(a[i]+k>a[n-1])
        {
            break;
        }
        if(num[a[i]]!=0)
        {
            if(num[a[i]+k]!=0)
            {
                res++;
                num[a[i]]--;
                num[a[i]+k]--;
            }
        }
        if(k==0 && num[a[i]]>=2)
        {
            res++;
            num[a[i]]-=2;
        }
    }
    cout<<n-res;
    return 0;
}
