#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int maxLengthAwesome(int*arr, int n, int k) {
	unordered_map<int, int>ends;
	int *sums = new int[n];
	ends[n-1] = n - 1;
	sums[n-1] = arr[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (sums[i+1] <= 0) {
			ends[i] = ends[i+1];
			sums[i] = sums[i+1] + arr[i];
		}
		else {
			ends[i] = i;
			sums[i] = arr[i];
		}
	}
	int sum = 0;
	int end = 0;
	int res = 0;
	int temp = 0;
	for (int i=0; end < n;++i) {
		while (end < n && sum + sums[end] <= k) {
			sum = sum + sums[end];
			end = ends[end] + 1;		
		}
		sum -= i < end ? arr[i] : 0;
		res = max(end-i,res);
		end = max(end, i+1);
	}
	return res;
}
void main() {
	//int a[] = { 1,2,-1,-3,8,1,1,1,-4,3,3 };
	int a[] = { 3,-2,-4,0,6};
	int n = sizeof(a) / sizeof(int);
	cout << maxLengthAwesome(a, n, -2);
}