//在字符串末尾加上字符，使整体为回文串
#include <iostream>
#include <string>
#include<vector>
#include<iterator>
#include<sstream>
#include<algorithm>
using namespace std;
//left:左边界    right:右边界    mid:中间值   radius:半径  
//left_i_left:对称点左边界   left_i:i关于mid的对称点
int manacher(string str) {
	int n = str.size();
	string str1;
	for (int i = 0; i < n; ++i) {
		str1 += "#";
		str1 += str[i];
	}
	str1 += "#";
	int left = 0, right = 0, mid = 0, r = 1, t, left_i,left_i_left;
	int *array=new int[2*n+1];
	array[0] = 1;
	for (int i = 1; i < 2 * n + 1; ++i) {
		if (right == 2 * n)
			return left/2;
		if (i >= right) {
			t = 1;
			while (t <= i && i + t < 2 * n + 1 && str1[i - t] == str1[i + t])
				++t;
			array[i] = t;
			if (i+t-1 > right) {
				left = i - t+1;
				mid = i;
				right = i + t-1;
			}
		}
		else if (i < right) {
			left_i = 2 * mid - i;
			left_i_left = left_i - array[left_i]+1;
			if (left_i_left > left)
				array[i] = array[left_i];
			else if (left_i_left = left) {
				t = left_i - left + 1;
				while (t <= i && i + t < 2 * n + 1 && str1[i - t] == str1[i + t])
					++t;
				array[i] = t;
				if (i + t - 1 > right) {
					left = i - t + 1;
					mid = i;
					right = i + t - 1;
				}
			}
			else if (left_i_left < left)
				array[i] = left_i - left + 1;
		}
	}
	return -1;
}

void main()
{
	string str = "1219";
	int i= manacher(str);
	if (i == 0) {
		cout << str;
		return;
	}
	if (i == -1)
		i = str.size();
	string t = str.substr(0, i);
	char *left = &t[0];
	char *right = &t[i-1];
	while (left<right) {
		swap(*left,*right);
		++left;
		--right;
	}
	str = str + t;
	cout << str;
}