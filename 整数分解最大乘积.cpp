#include <iostream>
#include<vector>
using namespace std;
//不相同
//http://blog.csdn.net/qq_23100787/article/details/48549525
//int main() { 
//	vector<int>vec;
//	int n, i = 2;
//	cin >> n;
//	int sum = 0;
//	while (sum+i<n) {
//		sum += i++;
//	}
//	--i;
//	int res=1;
//	if (n - sum == i) {//若剩余值（n-sum）等于i
//		for (int j = 3; j <= i + 1; ++j) {
//			if (j == i + 1)
//				res *= (j + 2);
//			else
//				res *= j;
//		}
//	}
//	else {//若剩余值（n-sum）小于i
//		int k = n - sum;
//		for (int j = i; j >= 2; --j) {
//			if (k > 0) {
//				res *= (j + 1);
//				--k;
//			}
//			else
//				res *= j;
//		}
//	}
//	cout << res;
//	return 0; }
int main() {
	int n;
	cin >> n;
	int t = pow(3,n/3);
	n = n % 3;
	if (n == 1)
		t = t / 3 * 4;
	else if (n == 2)
		t = t * 2;
	cout << t;
	return 0;
}