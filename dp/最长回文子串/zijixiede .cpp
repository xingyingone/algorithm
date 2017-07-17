#include <iostream>
#include <string>
#include<vector>
#include<iterator>
#include<sstream>
#include<algorithm>
using namespace std;
//left:��߽�    right:�ұ߽�    mid:�м�ֵ   radius:�뾶  
//left_i_left:�ԳƵ���߽�   left_i:i����mid�ĶԳƵ�
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
		/*if (right == 2 * n)
			break;*/
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
	sort(array, array + 2 * n + 1);
	return array[2 * n]-1;
}

void main()
{
	string str = "txaxaxax";
	cout << manacher(str);
}