//ʵ��һ������������һ�����飬Ҫ��ʹ�������и���������������ǰ��
//ʵ��һ������������һ�����飬Ҫ��ʹ�������и�����ǰ�����ں������м�
#include<stdio.h>
#include<stdlib.h>

//�������Ԫ��
void print(int *arr, int len);
//����������
void swap(int *left, int *right);
//�������������ں���
void sort_two(int *arr, int len);
//����������ǰ�棬0�����м䣬�������ں���
void sort_three(int *arr, int len);

int main()
{
	int arr[11] = { 1,0,-2,5,7,8,-1,-5,-9,-7,0 };
	printf("����ǰ��\n");
	print(arr, 11);

	printf("�����\n");
	//    sort_two(arr,11);
	sort_three(arr, 11);
	print(arr, 11);

	return 0;
}

//�������������ں��棬ʵ����˫ɫ�������⣬���ƿ��ŵ�˼��
void sort_two(int *arr, int len)
{
	int left = 0, right = len - 1;
	while (left < right)
	{
		//���������ҵ�һ������ʱ����ѭ��
		while (arr[left] <= 0)
			left++;
		//���������ҵ�һ��������ʱ����ѭ��
		while (arr[right] > 0)
			right--;
		//һ��Ҫ��
		if (left < right)
			swap(arr + left, arr + right);
		left++;
		right--;
	}
}

//ʵ������ɫ��������
void sort_three(int *arr, int len)
{
	int left, curr, right;//��ɫ�Ĺ���ָ��
	left = 0;//��¼��������ĩβ����һ��Ԫ��
	curr = 0;//��¼0���е���һ��Ԫ��
	right = len - 1;//��¼��������ǰ�˵�ǰһ��Ԫ��

	while (curr <= right)
	{
		if (arr[curr] == 0)//0
			curr++;
		else if (arr[curr] < 0)//����
		{
			swap(arr + curr, arr + left);
			curr++;
			left++;
		}
		else//����
		{
			swap(arr + curr, arr + right);
			right--;
		}
	}
}

void swap(int *left, int *right)
{
	*left ^= *right;
	*right ^= *left;
	*left ^= *right;
}

void print(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%4d", *(arr + i));
	printf("\n");
}