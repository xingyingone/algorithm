#include<iostream>
#include<string>
#include<vector>
#include"assert.h"
using namespace std;
vector<int> getNextArray(string str) {
	int n = str.size();
	vector<int>next(n);
	next[0] = -1;
	next[1] = 0;
	int cn = 0;
	for (int i = 2; i <= n - 1;) {
		if (str[i] == str[cn])
			next[i++] = ++cn;
		else if (cn > 0)
			cn = next[cn];
		else
			next[i++] = 0;
	}
	for (int i = 0; i <= n - 1; i++)
		cout << next[i] << "  ";
	cout << endl;
	return next;
}
int kmp(string s, string m) {
	if (m.size() < 1 || s.size() < m.size()) {
		return -1;
	}
	int si = 0;
	int mi = 0;
	vector<int>next = getNextArray(s);
	while (si < s.size() && mi < m.size()) {
		if (s[si] == m[mi]) {
			si++;
			mi++;
		}
		else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}
	}
	return mi == m.size()? si - mi : -1;
}
int main() {
	string str1 = "abcabcababaccc";
	string str2 = "ababa";
	cout<<kmp(str1, str2);
	return 0;
}