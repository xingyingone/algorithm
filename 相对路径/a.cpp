#include<iostream>
#include<string>
using namespace std;
char* getpath(char*a, char*b,char*temp)
{
	if (a == NULL || b == NULL)
	{
		cout << "error";
		return NULL;
	}
	//����ָ������·���в�ͬĿ¼����ʼ·��
	char*diff1 = a;
	char*diff2 = b;
	while (*a != '\0' && *b != '\0')
	{
		//���Ŀ¼��ͬ
		if (*a == *b)
		{
			if (*a == '/')
			{
				diff1 = a;
				diff2 = b;
			}
			++a;
			++b;
		}
		else
			//��ͬ��Ŀ¼
		{	
			diff1++;
			while (*diff1 != '\0')
			{
				if (*diff1 == '/')
				{
					strcat(temp,"../");
				}
				diff1++;
			}
			diff2++;
			strcat(temp, diff2);
			break;
		}
	}
	return temp;
}
void main()
{
	char a[] = "/qihoo/app/a/b/c/d/new.c";
	char b[] = "/qihoo/app/1/2/test.c";
	char temp[1024] = {0};
	cout << getpath(a,b,temp);
}