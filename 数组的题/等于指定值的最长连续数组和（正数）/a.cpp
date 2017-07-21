#include<iostream>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
int maxint(int *a, int n, int m) {
	map<int, int>imap;
	imap[0] = -1;
	int i = 0, sum = 0, res = -1, res1 = -1, res2 = -1;
	for ( ; i <= n - 1; ++i) {
		sum += a[i];
		imap[sum] = i;
	}
	map<int, int>::reverse_iterator it = imap.rbegin();
	while (it!= imap.rend()) {
		if (it->first == m)
			res1 = imap[m];
		else if (it->first > m) {
			if (imap.count(it->first - m)) {
				res2 = imap[it->first] - imap[it->first - m];
			}
		}	
		res = max(max(res1, res2), res);
		++it;
	}
	return res;
}
void main() {
	int a[] = {1,2,1,1,1,4,1,1,1,1,5,1,1,1,2};
	int n = sizeof(a) / sizeof(int);
	cout << maxint(a, n, 5);
}