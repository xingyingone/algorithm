#include<iostream>
#include<cmath>
using namespace std;
//int getlen(int n) {
//	int len = 0;
//	while (n != 0) {
//		++len;
//		n /= 10;
//	}
//	return len;
//}
//void get_res(int n, int*a)
//{
//	if (n<1)
//		return;
//	int len = getlen(n);
//	if (len == 1) {
//		for (int i = 1; i <= n; ++i)
//			++a[i];
//		return;
//	}
//	int temp = (int)pow(10, len - 1);
//	int first = n / temp;
//	for (int i = 1; i <= first; ++i) {//最大位
//		if (i == first)
//			a[i] += n%temp + 1;
//		else
//			a[i] += temp;
//	}
//	for (int i = 0; i <= 9; ++i)//其他位
//	{
//		a[i] += first*(len - 1)*(temp / 10);
//	}
//
//	get_res(n%temp, a);
//}
//int main() {
//	int n;
//	cin >> n;
//	int a[10] = { 0 };
//	get_res(n, a);
//	for (int i = 0; i <= 8; ++i)
//		cout << a[i] << " ";
//	cout << a[9];
//	return 0;
//}

int getlen(int n) {
	int len = 0;
	while (n != 0) {
		++len;
		n /= 10;
	}
	return len;
}
int NumberOf1Between1AndN_Solution(int n)
{
	if (n<1)
		return 0;
	int len = getlen(n);
	if (len == 1)
		return 1;
	int temp = pow(10, len - 1);
	int first = n / temp;
	int firstone = first == 1 ? n%temp + 1 : temp;
	int otherone = first*(len - 1)*(temp / 10);
	return firstone + otherone + NumberOf1Between1AndN_Solution(n%temp);
}
int main() {
	cout << NumberOf1Between1AndN_Solution(134);
}