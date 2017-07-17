#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxGap(vector<int> A, int n) {
	int MIN = A[0], MAX = A[0];
	for (int i = 1; i<n; ++i) {
		if (A[i] < MIN)
			MIN = A[i];
		if (A[i]>MAX)
			MAX = A[i];
	}
	if (MIN == MAX)
		return 0;
	int gap = (MAX - MIN);
	vector<int>vec;
	vector<vector<int> >ivec(n + 1, vec);
	int pos;
	for (int i = 0; i<n; ++i) {
			pos = (A[i] -MIN)*n/ gap;
		ivec[pos].push_back(A[i]);
	}
	int res = 0;
	int j = 0;//��һ���ǿ�Ͱ
	int t = 0;//��һ���ǿ�Ͱ
	int i = 0;//����
	while (i <= n) {
		if (ivec[i].size() != 0) {//��һ��Ͱ ���һ��Ͱ �϶��ǿ�
			j = i;
			++i;
		}
		else if (ivec[i].size() == 0) {
			t = i + 1;
			while (t <= n && ivec[t].size() == 0) {
				++t;
			}
			i = t;
			sort(ivec[j].begin(), ivec[j].end());
			sort(ivec[t].begin(), ivec[t].end());
			res = max(res, ivec[t].front() - ivec[j].back());
		}
	}
	return res;
}
int main()
{
	int a[] = { 3,1,2,4,9,8,7 };
	int n = sizeof(a) / sizeof(int);
	vector<int> A(a,a+n);
	cout << maxGap(A,n);
	return 0;
}