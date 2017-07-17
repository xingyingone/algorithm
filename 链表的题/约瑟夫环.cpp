#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<list>
using namespace std;
namespace aa {
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1 || m<1)
			return -1;
		int *tmp = new int[n];
		int count = 0;
		int pos = 0;
		int gap = 0;
		while (count<n) {
			gap = 0;
			while (gap<m - 1) {
				if (tmp[pos] == -1) {
					pos = (pos + 1) % n;
				}
				else {
					pos = (pos + 1) % n;
					++gap;
				}
			}
			while (tmp[pos] == -1) {
				pos = (pos + 1) % n;
			}
			++count;
			tmp[pos] = -1;
		}
		delete[]tmp;
		return pos;
	}
}
namespace bb {
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1 || m<1)
			return -1;
		int *tmp = new int[n];
		int count = 0;
		int pos = -1;
		int gap = 0;
		while (count<n) {
			pos = (pos + 1) % n;
			if (tmp[pos] == -1)
				continue;
			++gap;
			if (gap == m) {
				tmp[pos] = -1;
				gap = 0;
				++count;
			}
		}
		delete[]tmp;
		return pos;
	}
}
namespace cc {
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1 || m<1)
			return -1;
		list<int>ilist;
		for (int i = 0; i < n; ++i)
			ilist.push_back(i);
		list<int>::iterator cur = ilist.begin();
		list<int>::iterator next = ilist.begin();
		while (ilist.size()>1) {
			for (int i = 1; i < m; ++i) {
				++cur;
				if (cur == ilist.end())
					cur = ilist.begin();
			}
			next = ++cur;
			if (next == ilist.end())
				next = ilist.begin();
			--cur;
			ilist.erase(cur);
			cur = next;
		}
		return *(cur);
	}
}
void main() {
	cout << cc::LastRemaining_Solution(5,3);
}