#include<iostream>
#include<algorithm>
using namespace std;
int fun(int *a, int n, int sum) {
	int **dp = new int*[n];
	for (int i = 0; i <= sum; ++i)
		dp[i] = new int[n];
	for (int i = 0; i <= n - 1; ++i)
		dp[i][0] = 0;
	for (int j = 1; j <= sum; ++j) {
		if (j - a[0] < 0)
			dp[0][j] = INT_MAX;
		else
			dp[0][j] = dp[0][j - a[0]] + 1;
	}
	for (int i = 1; i < n; ++i) {
		for(int j = 1; j <= sum; ++j ) {
			if (j - a[i] >= 0)
				dp[i][j] = min(dp[i][j - a[i]] + 1, dp[i - 1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n-1][sum]>20000?-1: dp[n - 1][sum];
}
void main() {
	int arr[] = {3,5};
	int n = sizeof(arr) / sizeof(int);
	int sum = 2;
	cout << fun(arr,n,sum);
}