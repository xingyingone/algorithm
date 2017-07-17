#include<iostream>
using namespace std;
void sort(int*a,int start,int end) {
	if (start >= 0 && start<=end) {
		int temp = a[start];
		int left = start, cur = start, right = end;//（三色问题）left：记录0末尾后一个数   curr:记录1末尾后一个数  right：记录2首部前一个元素
		while (cur >= 0 && cur <= right) {
			if (a[cur] < temp) {
				swap(a[cur], a[left]);
				++left;
				++cur;
			}
			else if (a[cur] == temp)
				++cur;
			else {
				swap(a[cur], a[right]);
				--right;
			}
		}
		sort(a, start, left - 1);
		sort(a, cur, end);
	}
}
int main()
{
	int arr[11] = { 1,2,3,4,1,1,0,-1,1,1};
	int n = sizeof(arr) / sizeof(int);
	sort(arr, 0,n-1);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << "  ";
	return 0;
}