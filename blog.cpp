#include <iostream>
#include<ctime>//�������ͷ�ļ�
#include<cstdlib>//�������ͷ�ļ�
using namespace std;
int main()
{
	int count, i = 0, num, sum = 0, Sum = 0, j, Num = 0, xum;
	int a[500];//ÿ�����е������������
	int b[1000];//���������
	int c[500];//�洢ÿ�����еĽ��
	char ch[500];//���������������������
	cout << "���������������������" << endl;
	cin >> count;//����������
	srand(time(0));
	while (i != count)//�������ÿ������������������
	{
		num = rand() % 4;
		if (num > 1)
		{
			a[i] = num;
			i++;
		}
	}
	for (j = 0; j < count; j++)//����һ����Ҫ�������ٸ������
	{
		sum = a[j] + sum + 1;//�����������
		Num = a[j] + Num;//�����������
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

