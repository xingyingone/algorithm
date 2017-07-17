//实现一个函数，给定一个数组，要求使得数组中负数在所有正数的前面
//实现一个函数，给定一个数组，要求使得数组中负数在前正数在后零在中间
#include<stdio.h>
#include<stdlib.h>

//输出数组元素
void print(int *arr, int len);
//交换两个数
void swap(int *left, int *right);
//将所有正数排在后面
void sort_two(int *arr, int len);
//将负数排在前面，0放在中间，整数排在后面
void sort_three(int *arr, int len);

int main()
{
	int arr[11] = { 1,0,-2,5,7,8,-1,-5,-9,-7,0 };
	printf("排序前：\n");
	print(arr, 11);

	printf("排序后：\n");
	//    sort_two(arr,11);
	sort_three(arr, 11);
	print(arr, 11);

	return 0;
}

//将所有正数排在后面，实质是双色排序问题，类似快排的思想
void sort_two(int *arr, int len)
{
	int left = 0, right = len - 1;
	while (left < right)
	{
		//从左往右找到一个正数时跳出循环
		while (arr[left] <= 0)
			left++;
		//从右往左找到一个非正数时跳出循环
		while (arr[right] > 0)
			right--;
		//一定要有
		if (left < right)
			swap(arr + left, arr + right);
		left++;
		right--;
	}
}

//实质是三色排序问题
void sort_three(int *arr, int len)
{
	int left, curr, right;//三色的工作指针
	left = 0;//记录负数序列末尾的下一个元素
	curr = 0;//记录0序列的下一个元素
	right = len - 1;//记录正数序列前端的前一个元素

	while (curr <= right)
	{
		if (arr[curr] == 0)//0
			curr++;
		else if (arr[curr] < 0)//负数
		{
			swap(arr + curr, arr + left);
			curr++;
			left++;
		}
		else//正数
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