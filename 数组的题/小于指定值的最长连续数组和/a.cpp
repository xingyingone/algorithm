#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//不回退  复杂度n
int maxLengthAwesome(int*arr, int n, int k) {
	unordered_map<int, int>max_index;
	int *min_value = new int[n];
	max_index[n-1] = n - 1;//累加和的最右坐标
	min_value[n-1] = arr[n - 1];//i到后面的最小累加和
	for (int i = n - 2; i >= 0; --i) {
		if (min_value[i+1] <= 0) {
			max_index[i] = max_index[i+1];
			min_value[i] = min_value[i+1] + arr[i];
		}
		else {
			max_index[i] = i;
			min_value[i] = arr[i];
		}
	}
	int sum = 0;
	int end = 0;
	int res = 0;
	for (int i=0; end < n;++i) {
		while (end < n && sum + min_value[end] <= k) {
			sum = sum + min_value[end];
			end = max_index[end] + 1;		
		}
		sum -= i < end ? arr[i] : 0;
		res = max(end-i,res);
		end = max(end, i+1);
	}
	return res;
}
int main() {
	//int a[] = { 1,2,-1,-3,8,1,1,1,-4,3,3 };
	int a[] = { 4,3,-2,6,7,-3,-1};
	int n = sizeof(a) / sizeof(int);
	cout << maxLengthAwesome(a, n, 4)<<endl;
	return 0;
}