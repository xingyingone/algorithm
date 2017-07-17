/*����Ŀ��
���������ַ���str1��str2���ٸ�����������ic��dc��rc���ֱ������롢ɾ�����滻һ���ַ��Ĵ��ۣ�
���ؽ�str1�༭��str2����С���ۡ�
��������
str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 2��
��"abc"�༭��"adc"����'b'�滻��'d'�Ǵ�����С�ģ����Է���2��
str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 100��
��"abc"�༭��"adc"����ɾ��'b'��Ȼ�����'d'�Ǵ�����С�ģ����Է���8��
str1 = "abc"��str2 = "abc"��ic = 5��dc = 3��rc = 2��
���ñ༭�ˣ���������һ�����ַ��������Է���0��*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[256][256];

void main() {
	string str1 = "abc";
	string str2 = "adc";
	int ic=11, dc=1, rc=111;    // ����ɾ���滻����  
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