//暴力
#include<iostream>
using namespace std;
int exchangeMoney(int *arr, int n, int aim) {
	int **dp = new int*[n];
	for (int i = 0; i < n; ++i) {//new dp数组
		dp[i] = new int[aim+1];
		memset(dp[i], 0,(aim + 1) * sizeof(int));
	}
	for (int i = 0; i < n; ++i) {//初始化纵轴
		dp[i][0] = 1;
	}
	int j = 0;
	while (j + arr[0] <= aim) {//初始化横轴
		j += arr[0];
		dp[0][j] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (j = 1; j <= aim; ++j) {
			if (j - arr[i] >= 0)
				dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n-1][aim];
}
void main() {
	int arr[] = { 5,10,25,1 };
	int n = sizeof(arr) / sizeof(int);
	int aim = 15;
	cout << exchangeMoney(arr, n, aim);
}