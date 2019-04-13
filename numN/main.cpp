#include<iostream>
using namespace std;
int main()
{
	long long a,b,n;
	long long sa,sn,count;
	while(cin>>a>>b>>n)
	{
		sn = n;
		sa = a % b;    // 此时的sa*10对b取余后得到小数点后第一位
		count = 0;
		while(sn--)
		{
			if(sa == b)  //取余之后会等于零
				break;
			if(sa < b)
			{
				sa = sa * 10;
			}
			else
			{
				//除法法则，逐步运算
				sa = sa % b;
				cout<<sa;
				sa = sa * 10;

				if(!sa)
					break;  //后面都是零则直接跳出循环

			}
			count++;
			if(sa % b == a % b) // 减掉循环的数
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
				cout << sa / b; //逐步输出n后三位的每一位
				sa = sa % b;
				sa = sa * 10;
			}
		}
	}
	return 0;
}

