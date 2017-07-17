#include<iostream>
#include<vector>
using namespace std;
//void insert_sort(int*A, int start, int end) {
//	if (A == NULL || start == end)
//		return;
//	for (int i = start, j = start+1; j <= end;++j) {
//		i = j;
//		while (i >= 1 && A[i] < A[i - 1]) {
//			swap(A[i],A[i-1]);
//			--i;
//		}
//	}
//}
//int partition(int*A,int start,int end,int pivotId) {
//	if (start <= end) {
//		int temp = A[pivotId];
//		int i = start, j = end;
//		while (i < j) {
//			while (i<j && A[j]>temp)
//				--j;
//			if (i < j)
//				A[i++] = A[j];
//			while (i < j && A[i] < temp)
//				++i;
//			if (i < j)
//				A[j--] = A[i];
//		}
//		A[i] = temp;
//		return i;
//	}
//	return -1;
//}
//int bfprt(int*A,int start,int end,int k) {
//	if (A == NULL || end <= 0 || end < k-1)
//		return -1;
//	if (end - start + 1 <= 5) {
//		insert_sort(A,start,end);
//		return A[k-1];
//	}
//	int t = start - 1;
//	for (int st = start, ed; (ed = st + 4) <= end;st+=5) {
//		insert_sort(A, st, ed);
//		++t;
//		swap(A[t],A[st+2]);
//	}
//	int pivotId = (1 + t) >> 1;
//	bfprt(A,start,end, pivotId);
//	int m = partition(A,start,end, pivotId);
//	int cur = m - 1 + start;
//	if (k == cur)
//		return A[m];
//	else if (k < cur)
//		return bfprt(A, start, m - 1, k);
//	else
//		return bfprt(A, m + 1, end, k - cur);
//}
//void main() {
//	int a[] = {1,6,4,7,4,9,4,99,1};
//	int n = sizeof(a) / sizeof(int);
//	cout << bfprt(a,0,n-1,3);
//}
// 线性查找算法(BFPRT), 最坏情况下时间复杂度也为O(N)，克服随机选择最坏情况下的困难  
/*
1:将n个元素每5个一组，分成n/5(上界)组。
2：取出每一组的中位数，任意排序方法，比如插入排序。
3：递归的调用selection算法查找上一步中所有中位数的中位数，设为x，偶数个中位数的情况下设定为选取中间小的一个。

4： 用x来分割数组，设小于等于x的个数为k，大于x的个数即为n-k。

5. 若i==k，返回x；若i<k，在小于x的元素中递归查找第i小的元素；若i>k，在大于x的元素中递归查找第i-k小的元素。

其时间复杂度为T(n) <= T(n/5)+T(7/10*n)+O(n)
*/


// 插入排序  
void insertionSort(int *arr, int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j]> temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}

}


// 找到接近中位数的下标，不是随机选择，选择中位数的中位数的下标 
int getPivotId(int *arr, int l, int r) {
	if (r - l + 1 < 5) {
		insertionSort(arr, l, r);
		return (r + l) >> 1;
	}
	int t = l - 1;
	for (int i = l; i + 4 <= r; i = i + 5) {
		insertionSort(arr, i, i + 4);
		swap(arr[++t], arr[i + 2]);
	}
	return getPivotId(arr, l, t);

}

// 根据BFPRT算法选择的下标值进行划分  
int partition2(int *arr, int l, int r) {
	int pid = getPivotId(arr, l, r);
	swap(arr[l], arr[pid]);
	int pivot = arr[l];
	int i = l, j = r;
	while (i < j) {
		for (; j > i; j--) {
			if (arr[j] < pivot) {
				arr[i++] = arr[j];
				break;
			}
		}

		for (; i < j; i++) {
			if (arr[i] > pivot) {
				arr[j--] = arr[i];
				break;
			}
		}

	}
	arr[i] = pivot;
	return i;
}


// 根据BFPRT算法求无序数组中第k小的数据---主调用函数  

int BFPRT(int *arr, int l, int r, int k) {
	int i = partition2(arr, l, r);
	int p = i - l + 1;
	if (k == p) return arr[i];
	else if (k < p) return BFPRT(arr, l, i - 1, k);
	else return BFPRT(arr, i + 1, r, k - p);
}
void main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int n = sizeof(a) / sizeof(int);
	cout << BFPRT(a,0,n-1,10);
}