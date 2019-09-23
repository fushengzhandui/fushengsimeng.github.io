#include <iostream>
#include<ctime>//随机函数头文件
#include<cstdlib>//随机函数头文件
using namespace std;
int main()
{
	int count, i = 0, num, sum = 0, Sum = 0, j, Num = 0, xum;
	int a[500];//每道题中的运算符数数组
	int b[1000];//随机数数组
	int c[500];//存储每道题中的结果
	char ch[500];//存出随机产生的算术运算符
	cout << "请输入你想产生的题数：" << endl;
	cin >> count;//产生的题数
	srand(time(0));
	while (i != count)//随机生成每道题产生的算数运算符
	{
		num = rand() % 4;
		if (num > 1)
		{
			a[i] = num;
			i++;
		}
	}
	for (j = 0; j < count; j++)//计算一共需要产生多少个随机数
	{
		sum = a[j] + sum + 1;//随机数的总数
		Num = a[j] + Num;//运算符的总数
	}
	srand(time(0));
	for (i = 0; i < sum; i++)
	{
		b[i] = rand() % 101;
	}
	srand(time(0));
	for (int k = 0; k < Num; k++)
	{
		xum = rand() % 4;
		if (xum == 0)
		{
			ch[k] = '+';
		}
		else if (xum == 1)
		{
			ch[k] = '-';
		}
		else if (xum == 2)
		{
			ch[k] = '*';
		}
		else if (xum == 3)
		{
			ch[k] = '/';
		}
	}
	int k = 0, x = 0;
	Sum = 0;
	for (j = 0; j < count; j++)
	{
		for (i = Sum; i < (Sum + a[j] + 1); i++)
		{
			if (ch[x] == '/')
			{
				while (b[i] % b[i + 1] != 0)
				{
					b[i] = rand() % 101;
					b[i + 1] = rand() % 101;
				}
			}
			cout << b[i] << ' ';
			if (i == Sum + a[j])
				cout << "=";
			else
			{
				cout << ch[x];
				x = x + 1;
			}
		}
		cout << endl;
		Sum = a[j] + Sum + 1;
	}
	system("pause");
	return 0;
}

