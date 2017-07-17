#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int findLCS(string A, int n, string B, int m) {
	//int **b = new int *[m+1];
	//for (int i = 0; i<m+1; ++i)
	//	b[i] = new int[n];
	//for (int i = 0; i < m + 1; ++i) {
	//	for (int j = 0; j < n + 1; ++j)
	//		b[i][j] = 0;
	//}
	vector<int>a(n + 1);
	vector<vector<int> >b(m + 1, a);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (A[i] == B[j])
				b[j+1][i+1] = b[j][i] + 1;
			else
				b[j+1][i+1] = max(b[j][i+1], b[j+1][i]);
		}
	}
	string res = "";
	for (int i = n-1; i >0;) {
		for (int j = m-1; j > 0;) {
			if (A[i] == B[j]) {
				res.push_back(A[i]);
				--i;
				--j;
			}
			else {
				if (b[j][i+1] > b[j+1][i]) {
					//res.push_back(B[j]);
					--j;
				}
				else {
					//res.push_back(A[i]);
					--i;
				}
			}
		}
	}
	reverse(res.begin(),res.end());
	cout << res<<"  "<<res.size()<<endl;
	return b[m][n];
}
int main() {
	string str1 = "1A2C3D4B56";
	string str2 = "B1D23CA45B6A";
	cout << findLCS(str1,10,str2,12);
	return 0;
}
