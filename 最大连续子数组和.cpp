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
	printf("==========================================\n      ��ӭʹ���������������ͼ�����\n==========================================\n");
	printf("˵����\n     ����������������������֣�����д���뼸����������һ����ȷ��������ֿ�ʼ���㣬���س�֮���ٰ�����ctrl+z��������\n");
	while (scanf("%c", &input)!=EOF)//����ѭ��
	{
		if (input=='\n')
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//�����ʱ����
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
			right = 0;
			tot = 0;
			continue;
		}
		else if (input == ' ')
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//�����ʱ����
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
			right = 0;
			tot = 0;
			continue;
		}
		else if (input == '-')//ͳ�Ƹ���
		{
			while (!number.empty())
			{
				pop = number.front();
				number.pop();
				right = right * 10 + pop;//�����ʱ����
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
			right = 0;
			tot = 0;
			tot++;
		}
		else if (input-'0'>=0&&input-'0'<=9)//ͳ������
		{
			number.push(int(input-'0'));
		}
		else
		{
			while (tot--)
			{
				error.push('-');//ͳ������������ø���
			}
			tot = 0;
			error.push(input);//��¼������󸺺�
		}
	}
	if (!error.empty())
	{
		printf("���������������%d�����󣬷ֱ���:\n",error.size());
		while (!error.empty())
		{
			printf("%c ", error.front());
			error.pop();
		}
		printf("\n���ϴ������벻����\n");
	}
	printf("������Ч���룬��������Ϊ:%d\n",ans);
	system("pause");
	return 0;
}
