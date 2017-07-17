#include<iostream>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;
int* radixSort(int* A, int n) {
	if (A == NULL || n <= 1)
		return A;
	vector<int>vec;
	vector<vector<int> >ivec(10, vec);
	int MAX = A[0];
	for (int i = 1; i<n; ++i) {
		MAX = max(MAX, A[i]);
	}
	int len = 0;
	while (MAX) {
		++len;
		MAX = MAX / 10;
	}
	int t = 0;
	int temp;
	while (t<len) {
		for (int i = 0; i<n; ++i) {
			temp = (A[i] / (int)pow(10, t)) % 10;
			ivec[temp].push_back(A[i]);
		}
		int j = 0;
		for (int i = 0; i<10; ++i) {
			if (ivec[i].size()) {
				for (auto iter = ivec[i].begin(); iter != ivec[i].end(); ++iter)
					A[j++] = *iter;
				ivec[i].clear();
			}
		}
		++t;
	}
	return A;
}
void main() {
	int a[] = { 1,6,44,3,7,8 };
	int n = sizeof(a) / sizeof(int);
	int *b = radixSort(a, n);
	for (int i = 0; i < n; ++i)
		cout << b[i] << "  ";
}

///********************************************************
//*函数名称：GetNumInPos
//*参数说明：num 一个整形数据
//*          pos 表示要获得的整形的第pos位数据
//*说明：    找到num的从低到高的第pos位的数据
//*********************************************************/
//int GetNumInPos(int num, int pos)
//{
//	int temp = 1;
//	for (int i = 0; i < pos - 1; i++)
//		temp *= 10;
//
//	return (num / temp) % 10;
//}
//
///********************************************************
//*函数名称：RadixSort
//*参数说明：pDataArray 无序数组；
//*          iDataNum为无序数据个数
//*说明：    基数排序
//*********************************************************/
//#define RADIX_10 10    //整形排序  
//#define KEYNUM_31 10     //关键字个数，这里为整形位数  
//int* RadixSort(int* pDataArray, int iDataNum)
//{
//	int *radixArrays[RADIX_10];    //分别为0~9的序列空间  
//	for (int i = 0; i < 10; i++)
//	{
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数  
//	}
//
//	for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位  
//	{
//		for (int i = 0; i < iDataNum; i++)    //分配过程  
//		{
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//
//		for (int i = 0, j = 0; i < RADIX_10; i++)    //收集  
//		{
//			for (int k = 1; k <= radixArrays[i][0]; k++)
//				pDataArray[j++] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //复位  
//		}
//	}
//	return pDataArray;
//}
//
//void main() {
//	int a[] = { 1,6,44,3,7,8 };
//	int n = sizeof(a) / sizeof(int);
//	int *b = RadixSort(a, n);
//	for (int i = 0; i < n; ++i)
//		cout << b[i] << "  ";
//}