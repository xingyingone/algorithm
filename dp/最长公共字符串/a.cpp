/*【题目】
给定两个字符串str1和str2，返回两个字符串的最长公共子串。
【举例】
str1 = "1AB2345CD"，str2 = "12345EF"，返回"2345"。
【要求】
如果str1长度为M，str2长度为N，实现时间复杂度为O(MN)，额外空间复杂度为O(1)的方法。*/
#include<iostream>
#include<string>
using namespace std;
string fun(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	string str;
	if (m == 0 || n == 0)
		return str;
	int j = n - 1,i=0,arr=0,tmp=0,pos=0,MAX=0,t=0;
	while (j > 0) {
		i = 0;
		t = j;
		tmp = 0;
		while (i < m && j < n) {
			if (str1[i] == str2[j]) {
				arr = tmp + 1;
				if (arr > MAX) {
					MAX = arr;
					pos = j;
				}
				tmp = arr;
			}				
			else
				tmp = 0;
			++i;
			++j;
		}
		j=t-1;
	}
	i = 0;
	tmp = 0;
	while (i<m) {
		j = 0;
		t = i;
		tmp = 0;
		while (i < m && j < n) {
			if (str1[i] == str2[j]) {
				arr = tmp + 1;
				if (arr > MAX) {
					MAX = arr;
					pos = j;
				}
				tmp = arr;
			}
			else
				tmp = 0;
			++i;
			++j;
		}
		i=t+1;
	}
	return str2.substr(pos-MAX+1,MAX);
}
void main() {
	string str1 = "1AB2345CD";
	string str2 = "12345EF";
	cout << fun(str1, str2);
}