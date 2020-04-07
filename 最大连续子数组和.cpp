#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
	queue <int> number;
	queue <char> error;
	char input;
	int ans = 0;
	int tot = 0;
	int tbd = 0;
	int right = 0;
	int pop = 0;
	printf("==========================================\n      欢迎使用最大连续子数组和计算器\n==========================================\n");
	printf("说明：\n     您可以输入任意个整数数字，不用写输入几个，从您第一个正确输入的数字开始计算，按回车之后再按两次ctrl+z结束输入\n");
	while (scanf("%c", &input)!=EOF)//几个循环
	{
		if (input=='\n')
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//输出当时的数
			}
			if (tot % 2 == 1)
			{
				tbd -= right;
				if (tbd < 0)
				{
					tbd = 0;
				}
			}
			else
			{
				tbd += right;
			}
			ans = max(ans, tbd);
			if (right != 0)
			{
				tot = 0;
			}
			right = 0;
		}
		else if (input == ' ')
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//输出当时的数
			}
			if (tot % 2 == 1)
			{
				tbd -= right;
				if (tbd < 0)
				{
					tbd = 0;
				}
			}
			else
			{
				tbd += right;
			}
			ans = max(ans, tbd);
			if (right != 0)
			{
				tot = 0;
			}
			right = 0;
		}
		else if (input == '-')//统计负号
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//输出当时的数
			}
			if (tot % 2 == 1)
			{
				tbd -= right;
				if (tbd < 0)
				{
					tbd = 0;
				}
			}
			else
			{
				tbd += right;
			}
			ans = max(ans, tbd);
			if (right != 0)
			{
				tot = 0;
			}
			right = 0;
			tot++;
		}
		else if (input-'0'>=0&&input-'0'<=9)//统计数字
		{
			number.push(int(input-'0'));
		}
		else
		{
			while (tot--)
			{
				error.push('-');//统计输入多少无用负号
			}
			tot = 0;
			error.push(input);//记录输入错误负号
		}
	}
	if (!error.empty())
	{
		printf("您输入的内容中有%d处错误，分别是:\n",error.size());
		while (!error.empty())
		{
			printf("%c ", error.front());
			error.pop();
		}
		printf("\n以上错误输入不计算\n");
	}
	printf("根据有效输入，计算出结果为:%d\n",ans);
	system("pause");
	return 0;
}
