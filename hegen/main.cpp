#include <iostream>
#include <map>
//#include <sstream>
using namespace std;

int pre[1000*1000];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        pre[i] = i ;
    }
}

int find_pre(int i)
{
    int r = i;
    while(pre[r]!=r)
    {
        //cout<<"pre[r]="<<pre[r]<<" r="<<r<<endl;
        r = pre[r];
        //cout<<"diediedie"<<endl;
    }
    //cout<<"???"<<endl;
    while(i!=r)
    {
        int temp = pre[i];
        pre[i] = r;
        i = temp;
    }
    pre[i] = r;
    return r;
    /*
    if(pre[i]==i)
    {
        return pre[i];
    }
    return pre[i] = find_pre(pre[i]);*/
}


int main()
{
    int m,n;
    cin>>m>>n;
    init(m*n);
    long int k;
    cin>>k;

    int a,b;
    while(k--)
    {
        cin>>a>>b;
        if(find_pre(a-1) != find_pre(b-1))
        {
            pre[find_pre(a-1)] = find_pre(b-1);
        }
        /*
        if(a>b)
        {
            pre[b-1] = a-1;
        }
        else
        {
            pre[a-1] = b-1;
        }*/
        /*
        if(pre[b-1] == b-1)
        {
            pre[b-1] = a-1;
        }
        else
        {
            pre[a-1] = b-1;
        }*/
    }
    int tmp,num;
    num = 0;
    map<int ,int>c;
    //stringstream d;

    for(int i=0;i<m*n;i++)
    {

        tmp = find_pre(i);

        if(c.find(tmp) == c.end())
        {
            num++;
            c[tmp] = 1;
            //d<<tmp+1<<" ";
        }

    }
    //cout<<d.str()<<endl;
    cout<<num;
    return 0;
}
