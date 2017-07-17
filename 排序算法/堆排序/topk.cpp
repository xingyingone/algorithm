#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<map>
using namespace std;
void create_heap(vector<int>& input, int from, int to) {
	if (from <= to) {
			int max = from;
			if (2 * from + 1 <= to && input[max]<input[2 * from + 1])
				max = 2 * from + 1;
			if (2 * from + 2 <= to && input[max]<input[2 * from + 2])
				max = 2 * from + 2;
			if (max != from) {
				swap(input[max], input[from]);
				create_heap(input, max, to);
			}		
	}
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int>ivector;
	int n = input.size() - 1;
	int len = k - 1;
	if (k == 0 || k>n+1)
		return ivector;
	//建堆
	for (int i = (n-1) / 2; i >= 0;--i) {
		create_heap(input, i, n);
	}	
	//维护堆
	for (int i = k; i <= n;++i) {
		if (input[i] < input[0]) {
			swap(input[0] , input[i]);
			create_heap(input, 0, len);
		}
	}
	int t = k - 1;
	while (t >= 1) {
		swap(input[0], input[t]);
		create_heap(input, 0, t - 1);
		--t;
	}
	vector<int>res(input.begin(), input.begin()+k);
	return res;
}
void main() {
	int a[] = { 4,5,1,6,2,7,3,8 };
	vector<int> numbers(a,a+sizeof(a)/sizeof(int));
	numbers=GetLeastNumbers_Solution(numbers, 4);
	for (auto i : numbers)
		cout << i << "   ";
}

//void adjust_heap(int* A, int start, int end) {
//	if (start <= end) {
//		int max = start;
//		if (2 * start + 1 <= end && A[2 * start + 1]>A[max])
//			max = 2 * start + 1;
//		if (2 * start + 2 <= end && A[2 * start + 2]>A[max])
//			max = 2 * start + 2;
//		if (max != start) {
//			swap(A[start], A[max]);
//			adjust_heap(A, max, end);
//		}
//	}
//}
//int* heapSort(int* A, int n) {
//	// write code here
//	if (n <= 1)
//		return A;
//	//建堆
//	for (int i = (n - 2) / 2; i >= 0; --i) {
//		adjust_heap(A, i, n - 1);
//	}
//	//调整堆
//	while (n - 1 >= 0) {
//		adjust_heap(A, 0, n - 1);
//		swap(A[0], A[n - 1]);
//		--n;
//	}
//	return A;
//}
//void main() {
//	int a[] = { 4,5,2,1,3,6,7,8,9,10 };
//	int n = sizeof(a) / sizeof(int);
//	int *b = heapSort(a,n);
//	for (int i = 0; i <= n;++i) {
//		cout << b[i] << "   ";
//	}
//}