#include <iostream>

using namespace std;

int main()
{
    int a[200][200];//��
    int b[202][202];//ǽ

    int dect=0;//���� 0,1,2,3 0Ϊ��ʼ���� ���������ǰ����ת90��

    int m,n;//����
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i+1][j+1]=1;
        }
    }

    int mp=0,np=0; //��ǰ��ע��
    int fmp,fnp; //Ҫ�ߵ���һ����

    for(int i=0;i<m*n;i++)//����
    {
        cout<<a[mp][np];
        b[mp+1][np+1]=2;
        if(i!=m*n-1)
        {
            cout<<" ";
        }

        fmp=mp+1,fnp=np+1;
        if(dect==0)
        {

            fmp++;
        }
        else if(dect==1)
        {

            fnp++;
        }
        else if(dect==2)
        {

            fmp--;
        }
        else if(dect==3)
        {

            fnp--;
        }

        if(b[fmp][fnp] !=1 )
        {
            dect = (++dect)%4;
        }

        if(dect==0)
        {
            mp++;
        }
        else if(dect==1)
        {
            np++;
        }
        else if(dect==2)
        {
            mp--;
        }
        else if(dect==3)
        {
            np--;
        }
    }
    return 0;
}
