/*【题目】
给定两个字符串str1和str2，再给定三个整数ic、dc和rc，分别代表插入、删除和替换一个字符的代价，
返回将str1编辑成str2的最小代价。
【举例】
str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 2。
从"abc"编辑成"adc"，把'b'替换成'd'是代价最小的，所以返回2。
str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 100。
从"abc"编辑成"adc"，先删除'b'，然后插入'd'是代价最小的，所以返回8。
str1 = "abc"，str2 = "abc"，ic = 5，dc = 3，rc = 2。
不用编辑了，本来就是一样的字符串，所以返回0。*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[256][256];

void main() {
	string str1 = "abc";
	string str2 = "adc";
	int ic=11, dc=1, rc=111;    // 插入删除替换代价  
		memset(dp, 0, sizeof(int) * 256 * 256);
		int m = str1.size();
		int n = str2.size();
		for (int i = 1; i <= m; i++)
			dp[i][0] = dp[i - 1][0] + ic;
		for (int j = 1; j <= n; j++)
			dp[0][j] = dp[0][j - 1] + ic;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = min(dp[i - 1][j - 1] + rc, min(dp[i][j - 1] + ic, dp[i - 1][j] + dc));
			}
		}
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				cout << dp[i][j] << "  ";
			}
			cout << endl;
		}				
		cout << dp[m][n] << endl;
	}