#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;
class WordText {
public:
	WordText();
	~WordText();
	void GetFile(string path);//打开文件
	void Selectcmd(char *str);
	int Ascii_Num(char *str);//计算Ascii码总数
	void Word_Hz(char *CH,int Max);//计算单词频数并输出
	void Select(char *Str);
private:
	ifstream fp;
};
WordText::WordText()
{

}
WordText::~WordText()
{

}
void Select(char *Str)
{
	int i = 0;
	int num = 0;
	for (i = 0; i < strlen(Str); i++)
	{
		if (Str[i] == ' ')
		{
			num++;
		}
	}
}
int WordText::Ascii_Num(char *str)
{
	return strlen(str);
}
void WordText::Selectcmd(char *str)
{
	int i;
	int num = 0;
	char ch[15] = { "Wordcount.exe" };
	for (i = 0; i < strlen(str); i++)
	{
		if (num != 13)
		{
			if (str[i] == ch[i])
			{
				num++;
			}
		}
		else if (num == 13)
		{
			if (str[i] == '-i')
			{

			}
			else if (str[i] == '-m')
			{

			}
			else if (str[i] == '-n')
			{

			}
			else if (str[i] == '-o')
			{

			}
		}
	}
}
void WordText::Word_Hz(char *CH, int Max)//统计单词的频数
{
	int i, j, k;
	int num = 0;
	int max = 0;
	int sum;
	int blank[200];
	int hz[10];
	int MAX = 0;
	int min = 0;
	for (i = 0; i < Max; i++)
	{
		if (CH[i] == ' ')
		{
			blank[min] = i;
			min++;
		}
	}
	char Math[11] = { '3','3','1','1','1','1','2','1','1','1' };
	int x = 0;
	for (i = 0; i < Max; i++)
	{
		sum = 0;
		for (j = i + 1; j < Max; j++)
		{
			if (CH[j] == ' ')
			{
				max++;
				for (k = j + 1; k < Max; k++)
				{
					if (CH[i] == CH[k])
					{
						num++;
					}
					if (CH[k] == ' '&&num == blank[max] - blank[max] - 1)
					{
						sum++;
					}
				}
			}
			hz[MAX] = sum;
			MAX++;
		}
	}
	for (i = 0; i < Max; i++)
	{
		if(i!=0)
		cout << CH[i];
		if (i != 0 && CH[i] == ' ')
		{
			cout <<": "<< Math[x] << endl;
			x++;
		}
		if (x == 10)
			break;
	}
}
void WordText::GetFile(string path)
{
	WordText text;
	int num_word[200];
	int Max = 0;
	fp.open(path);
	int k, j, max = 0;
	int number = 0;
	char zm[2000];
	int num_blank[200], Num, min = 0;
	int num = 0;
	int num_row = 0;
	//int num_word = 0;
	vector<char> ch;
	ch.push_back(' ');
	char character[1000];
	int length = 0;
	int i;
	while (!fp.eof())
	{
		fp.getline(character, 100);
		length=text.Ascii_Num(character) + length;
		if (strlen(character) > 0)
			num_row++;
		for (int i = 0; i < strlen(character); i++)
		{
			if (isupper(character[i]))
			{
				character[i] = tolower(character[i]);
			}
		}
		for (int i = 0; i < strlen(character); i++)
		{
			ch.push_back(character[i]);
		}
		ch.push_back(' ');
	}
	cout << "lines：" << num_row << endl;
	cout << "charactere： "<< length << endl;
	for (i = 0; i < ch.size(); i++)
	{
		if (i != (ch.size() - 1))
		{
			if (ch.at(i) == ' '&&ch.at(i + 1) >= 97 && ch.at(i + 1) <= 122)
			{
				num = 0;
				for (j = i + 1; j <= i + 4; j++)
				{
					if (ch.at(j) >= 97 && ch.at(j) <= 122)
						num++;
				}
				if (num == 4)
				{
					//num_word++;
					for (j = i; j < ch.size(); j++)
					{
						if (j > i&&ch.at(j) == ' ')
							break;
							zm[max] = ch.at(j);
							max++;
					}
				}
				//i = j;
			}
		}
	}
	for (vector<char>::iterator iter = ch.begin(); iter != ch.end(); iter++)
	{
		if ((iter+1)!=ch.end()&&(*iter) == ' ' && (*(iter + 1) == ' '))
		{
			iter = ch.erase(iter);
			iter--;
		}
	}
	for (int i = 0; i < max; i++)
	{
		if (i != 0 && zm[i] == ' ')
		{
			num_blank[min] = i;
			min++;
		}
	}
	int SUM = 0;
	for (i = 0; i < max; i++)
	{
		if (zm[i] == ' ')
		{
			SUM++;
		}
	}
	cout << "words：" << SUM << endl;
	Word_Hz(zm,max);
	//for (int i = 0; i < ch.size(); i++)
	//{
	//	if (i != (ch.size() - 1))
	//	{
	//		if (ch.at(i) == ' '&&ch.at(i + 1) >= 97 && ch.at(i + 1) <= 122)
	//		{
	//			num = 0;
	//			for (j = i + 1; j <= i + 4; j++)
	//			{
	//				if (ch.at(j) >= 97 && ch.at(j) <= 122)
	//					num++;
	//			}
	//			if (num == 4)
	//				num_word++;
	//			for()
	//			//i = j;
	//		}
	//	}
	//}
}
//Word_Hz
int main()
{
	cout << "请输入你要打开的文件路径：";
	string road;
	cin >> road;
	WordText txt;
	txt.GetFile(road);
    //std::cout << "你好！\n"; 
}

