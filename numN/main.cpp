#include<iostream>
using namespace std;
int main()
{
	long long a,b,n;
	long long sa,sn,count;
	while(cin>>a>>b>>n)
	{
		sn = n;
		sa = a % b;    // ��ʱ��sa*10��bȡ���õ�С������һλ
		count = 0;
		while(sn--)
		{
			if(sa == b)  //ȡ��֮��������
				break;
			if(sa < b)
			{
				sa = sa * 10;
			}
			else
			{
				//��������������
				sa = sa % b;
				cout<<sa;
				sa = sa * 10;

				if(!sa)
					break;  //���涼������ֱ������ѭ��

			}
			count++;
			if(sa % b == a % b) // ����ѭ������
			{
				sn = n % count;
			}

		}
		if(!sa)
		{
			cout<<"000";
		}
		else
		{
			int i = 3;
			while(i--)
			{
				cout << sa / b; //�����n����λ��ÿһλ
				sa = sa % b;
				sa = sa * 10;
			}
		}
	}
	return 0;
}

