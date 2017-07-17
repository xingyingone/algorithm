#include<iostream>
#include<string>
#include<iterator>
#include<set>
#include<vector>
using namespace std;
//先把最小值填充在最后面，[pos，n-1]已排好序
int* bubbleSort(int* A, int n) {
	int pos = n - 1, temp = n - 1;
	for (int i = 0; i <= n-1; ++i) {
		pos = temp;
		for (int j = 0; j < pos; ++j) {
			if (A[j] > A[j + 1]) {
				temp = j;
				swap(A[j], A[j + 1]);
			}
		}
		if (pos == temp)
			break;
	}
	return A;
}
//先把最小值填充在最前面，[0,pos]已排好序
//void bubbleSort(int a[], int size)
//{
//	int Pos = 0, Temp = 0;
//	for (int i = 0; i < size - 1; i++)
//	{
//		Pos = Temp;
//		for (int j = size - 1; j >Pos; j--)
//		{
//			if (a[j - 1] > a[j])
//			{
//				swap(a[j - 1] , a[j]);
//				Temp = j;
//			}
//		}
//		if (Pos == Temp)
//			break;
//	}
//}

//void bubbleSort(int a[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = size - 1; j >i; j--)
//		{
//			if (a[j - 1] > a[j])
//			{
//				swap(a[j - 1], a[j]);
//			}
//		}
//	}
//}
int main() {
	int arr[] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	int n = sizeof(arr) / sizeof(int);
	copy(arr, arr + n, ostream_iterator<int>(cout, " "));
	bubbleSort(arr, n);
	cout << endl;
	copy(arr, arr + n, ostream_iterator<int>(cout, " "));
	return 0;
}