#include<iostream>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
int maxint(int *a, int n, int m) {
	multimap<int, int>imap;
	imap.insert(make_pair(0,-1));
	//imap[0] = -1;
	int i = 0, sum = 0, res = -1, res1 = -1;
	for (; i <= n - 1; ++i) {
		sum += a[i];
		imap.insert(make_pair(sum,i));
	}
	typedef multimap<int, int>::iterator int_multimap;
	multimap<int, int>::reverse_iterator it = imap.rbegin();	
	int cur = n - 1;
	while (it != imap.rend()) {
		if (imap.count(m - it->first))
		{
			pair<int_multimap, int_multimap> p = imap.equal_range(m - it->first);
			int_multimap iter = p.first;
			res1 = cur - iter->second;
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