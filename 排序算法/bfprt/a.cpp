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
// ���Բ����㷨(BFPRT), ������ʱ�临�Ӷ�ҲΪO(N)���˷����ѡ�������µ�����  
/*
1:��n��Ԫ��ÿ5��һ�飬�ֳ�n/5(�Ͻ�)�顣
2��ȡ��ÿһ�����λ�����������򷽷��������������
3���ݹ�ĵ���selection�㷨������һ����������λ������λ������Ϊx��ż������λ����������趨Ϊѡȡ�м�С��һ����

4�� ��x���ָ����飬��С�ڵ���x�ĸ���Ϊk������x�ĸ�����Ϊn-k��

5. ��i==k������x����i<k����С��x��Ԫ���еݹ���ҵ�iС��Ԫ�أ���i>k���ڴ���x��Ԫ���еݹ���ҵ�i-kС��Ԫ�ء�

��ʱ�临�Ӷ�ΪT(n) <= T(n/5)+T(7/10*n)+O(n)
*/


// ��������  
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


// �ҵ��ӽ���λ�����±꣬�������ѡ��ѡ����λ������λ�����±� 
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

// ����BFPRT�㷨ѡ����±�ֵ���л���  
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


// ����BFPRT�㷨�����������е�kС������---�����ú���  

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