#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getmax(int*a, int n) {
	if (a == NULL || n == 0)
		return 0;
	int cur = a[0], res = a[0];
	int *leftmax = new int[n];
	int *rightmax = new int[n];
	rightmax[0] = a[0];
	for (int i = 1; i < n; ++i) {
		cur = cur < 0 ? 0 : cur;
		cur += a[i];
		res = max(cur, res);
		leftmax[i] = res;
	}
	cur = a[n-1];
	rightmax[n-1] = a[n - 1];
	for (int j = n - 2; j >= 0; --j) {
		cur = cur < 0 ? 0 : cur;
		cur += a[j];
		rightmax[j] = max(cur, rightmax[j+1]);
	}
	for (int i = 0; i <= n - 2; ++i) {
		res = max(leftmax[i] + rightmax[i + 1], res);
	}
	return res;
}
void main() {
	int a[] = {1,2,3,-1,3,-5,10};
	int n = sizeof(a) / sizeof(int);
	cout << getmax(a,n);
}