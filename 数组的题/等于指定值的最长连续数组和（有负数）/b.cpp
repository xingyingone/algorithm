#include<iostream>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
int maxint(int *a, int n, int m) {
	map<int, int>imap;
	imap[0] = -1;
	int i = 0, sum = 0, res = -1, res1 = -1;
	for (; i <= n - 1; ++i) {
		sum += a[i];
		if(!imap.count(sum))
			imap[sum]=i;
	}
	typedef map<int, int>::iterator int_multimap;
	map<int, int>::reverse_iterator it = imap.rbegin();	
	int cur = n - 1;
	while (it != imap.rend()) {
		if (imap.count(m - it->first)){
			res1 = cur - imap[m - it->first];
			res = max(res1, res);
		}	 
		++it;
		--cur;
	}				
	return res;
}
int main() {
	int a[] = { 1,1,-1,1,-1,1,1,1,1,1 };
	int n = sizeof(a) / sizeof(int);
	cout << maxint(a, n, 5);
	return 0;
}