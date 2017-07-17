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
//*�������ƣ�GetNumInPos
//*����˵����num һ����������
//*          pos ��ʾҪ��õ����εĵ�posλ����
//*˵����    �ҵ�num�Ĵӵ͵��ߵĵ�posλ������
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
//*�������ƣ�RadixSort
//*����˵����pDataArray �������飻
//*          iDataNumΪ�������ݸ���
//*˵����    ��������
//*********************************************************/
//#define RADIX_10 10    //��������  
//#define KEYNUM_31 10     //�ؼ��ָ���������Ϊ����λ��  
//int* RadixSort(int* pDataArray, int iDataNum)
//{
//	int *radixArrays[RADIX_10];    //�ֱ�Ϊ0~9�����пռ�  
//	for (int i = 0; i < 10; i++)
//	{
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���  
//	}
//
//	for (int pos = 1; pos <= KEYNUM_31; pos++)    //�Ӹ�λ��ʼ��31λ  
//	{
//		for (int i = 0; i < iDataNum; i++)    //�������  
//		{
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//
//		for (int i = 0, j = 0; i < RADIX_10; i++)    //�ռ�  
//		{
//			for (int k = 1; k <= radixArrays[i][0]; k++)
//				pDataArray[j++] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //��λ  
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