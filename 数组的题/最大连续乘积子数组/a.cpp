#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int MaxProductSubstring(int *a, int length)
{
	int res = a[0], end1 = a[0], end2 = a[0], maxnum = a[0], minnum = a[0];
	for (int i = 1; i < length; ++i) {
		end1 = maxnum*a[i];
		end2 = minnum*a[i];
		minnum = min(min(end1, end2), a[i]);
		maxnum = max(max(end1, end2), a[i]);
		res = max(maxnum, res);
	}
	return res;
}
int main() {
	int a[] = { 0 ,10,8 };
	int n = sizeof(a) / sizeof(int);
	cout << MaxProductSubstring(a, n);
	return 0;
}