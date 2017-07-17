/*∂—≈≈–Ú(¥Û∂•∂—) 2011.9.14*/

#include <iostream>
#include<algorithm>
using namespace std;
void adjust(int* A, int start, int end) {
	int max = start;
	if (2 * start + 1 <= end && A[max]<A[2 * start + 1])
		max = 2 * start + 1;
	if (2 * start + 2 <= end && A[max]<A[2 * start + 2])
		max = 2 * start + 2;
	if (max != start) {
		swap(A[max], A[start]);
		adjust(A, max, end);
	}
}
int* heapSort(int* A, int n) {
	if (A == NULL || n <= 1)
		return A;
	for (int i = (n - 2) / 2; i >= 0; --i)
		adjust(A, i, n - 1);
	for (int i = 0; i <= n - 1; ++i) {
		adjust(A, 0, n - 1 - i);
		swap(A[0], A[n - 1 - i]);
	}
	return  A;
}
int main(int argc, char *argv[])
{
	int a[] = { 0,16,20,3,11,17,8,44,53,6 };
	int size = sizeof(a) / sizeof(int);
	int i;
	heapSort(a, size);
	for (i = 1; i <size; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}