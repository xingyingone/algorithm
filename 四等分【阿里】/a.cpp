#include<iostream>
using namespace std;
bool get(int*a,int n,int l, int l_sum, int r,int r_sum) {
	if (n < 7)
		return false;
	static int sum = 0;
	static int flag = 0;
	static bool res = false;
	if (l>=0 && r<=n-1 && l < r) {
		if (l_sum != r_sum) {
			return get(a, n, l + 1, l_sum + a[l + 1], r, r_sum) || get(a, n, l, l_sum , r-1, r_sum+a[r-1]);
		}
		else {
			if (flag == 0) {
				flag = 1;
				sum = l_sum;
				bool tmp = get(a, n, l + 2,  a[l + 2], r - 2, a[r - 2]);
				if (!tmp) {
					flag = 0;
					sum = 0;
					res= get(a, n, l + 1, l_sum + a[l + 1], r, r_sum) || get(a, n, l, l_sum, r - 1, r_sum + a[r - 1]);
				}
			}
			else if (flag==1) {
				if (l_sum == sum) {
					res= true;
				}
				else {
					res= get(a, n, l + 1, l_sum + a[l + 1], r, r_sum) || get(a, n, l, l_sum, r - 1, r_sum + a[r - 1]);
				}
			}
		}
	}
	return res;
}
void main() {
	int a[] = {10,2,11,13,1,1,1,1,1};
	int n = sizeof(a) / sizeof(int);
	if (get(a, n,0,a[0],n-1,a[n-1]))
		cout << "ok";
	else
		cout << "no";
}