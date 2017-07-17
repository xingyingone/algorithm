//aa bb 为逆序对
//cc dd 为自己写的归并排序
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
namespace aa{
	int InversePairCore(vector<int>& data, int*& copy, int start, int end);
		int InversePairs(vector<int> data) {
			if (data.size() <= 1) return 0;//如果少于等于1个元素，直接返回0
			int* copy = new int[data.size()];
			//初始化该数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中
			for (unsigned int i = 0; i<data.size(); i++)
				copy[i] = 0;
			//调用递归函数求解结果
			int count = InversePairCore(data, copy, 0, data.size() - 1);
			delete[] copy;//删除临时数组
			return count;
		}
		//程序的主体函数
		int InversePairCore(vector<int>& data, int*& copy, int start, int end)
		{
			if (start == end)
			{
				copy[start] = data[start];
				return 0;
			}
			//将数组拆分成两部分
			int length = (end - start) / 2;//这里使用的下标法，下面要用来计算逆序个数；也可以直接使用mid=（start+end）/2
										   //分别计算左边部分和右边部分
			int left = InversePairCore(data, copy, start, start + length) % 1000000007;
			int right = InversePairCore(data, copy, start + length + 1, end) % 1000000007;
			//进行逆序计算
			int i = start + length;//前一个数组的最后一个下标
			int j = end;//后一个数组的下标
			int index = end;//辅助数组下标，从最后一个算起
			int count = 0;
			while (i >= start && j >= start + length + 1)
			{
				if (data[i]>data[j])
				{
					copy[index--] = data[i--];
					//统计长度
					count += j - start - length;
					if (count >= 1000000007)//数值过大求余
						count %= 1000000007;
				}
				else
				{
					copy[index--] = data[j--];
				}
			}
			for (; i >= start; --i)
			{
				copy[index--] = data[i];
			}
			for (; j >= start + length + 1; --j)
			{
				copy[index--] = data[j];
			}
			//排序
			for (int i = start; i <= end; i++) {
				data[i] = copy[i];
			}
			//返回最终的结果
			return (count + left + right) % 1000000007;
		}
}
namespace bb {
	int getnum(vector<int>& data, int *copy, int start, int end) {
		if (start == end) {
			copy[start] = data[start];
			return 0;
		}
		int res = 0;
		int mid = (start + end) / 2;
		int leftnum = getnum(data, copy, start, mid);
		int rightnum = getnum(data, copy, mid + 1, end);
		int i = mid;
		int j = end;
		int pos = end;
		while (i >= start && j >= mid + 1) {
			if (data[i]>data[j]) {
				res += j - mid;
				copy[pos--] = data[i--];
				if (res >= 1000000007)
					res %= 1000000007;
			}
			else {
				copy[pos--] = data[j--];
			}
		}
		while (i >= start) {
			copy[pos--] = data[i--];
		}
		while (j >= mid + 1) {
			copy[pos--] = data[j--];
		}
		for (int i = start; i <= end; ++i)
			data[i] = copy[i];
		return (res + leftnum + rightnum) % 1000000007;
	}
	int InversePairs(vector<int> data) {
		if (data.size() == 0 || data.size() == 1)
			return data.size();
		int n = data.size();
		int *copy = new int[n];
		int res = getnum(data, copy, 0, data.size() - 1);
		delete[]copy;
		return res;
	}
}
namespace cc {

		void merge(int* A, int start, int mid, int end) {
			if (start == end)
				return;
			int*temp = new int[end - start + 1];
			int pos = 0;
			int i = start;
			int j = mid + 1;
			while (i <= mid && j <= end) {
				if (A[i]< A[j])
					temp[pos++] = A[i++];
				else
					temp[pos++] = A[j++];
			}
			while (i <= mid)
				temp[pos++] = A[i++];
			while (j <= end)
				temp[pos++] = A[j++];
			for (int i = 0; i <= end - start; ++i)
				A[i + start] = temp[i];
			delete[]temp;
		}
		int* mergeSort(int* A, int n) {
			if (A == NULL || n <= 1)
				return A;
			int i = 0, gap = 1;
			for ( gap = 1; gap<=n - 1; gap *= 2) {
				for ( i = 0; i +2*gap-1<= n - 1; i += 2 * gap) {
						merge(A, i, i + gap-1, i + 2 * gap - 1);
				}
			}
			if (i + gap-1 <= n - 1)
				merge(A,i,i+gap-1,n-1);
			return A;
		}
}
namespace dd {
	void merge(int* A, int* copy, int start, int end) {
		if (start == end) {
			copy[start] = A[start];//防止copy[start]未被初始化
			return;
		}		
		int mid = (start + end) / 2;
		merge(A, copy, start, mid);
		merge(A, copy, mid+1, end);
		int i = start;
		int j = mid + 1;
		int pos = 0;
		while (i<=mid && j<=end) {
			if (A[i] < A[j])
				copy[pos++] = A[i++];
			else
				copy[pos++] = A[j++];
		}
		while(i<=mid)
			copy[pos++] = A[i++];
		while(j<=end)
			copy[pos++] = A[j++];
		for (int i = start; i <= end; ++i)
			A[i++] = copy[i++];
	}
	int* mergeSort(int* A, int n) {
		if (A == NULL || n <= 1)
			return A;
		int *copy = new int[n];
		merge(A, copy, 0, n-1);
		delete[]copy;
		return A;
	}
}
void main() {
	
	int a[] = { 1,2,3,4,5,6,7,0};
	int n = sizeof(a) / sizeof(int);
	//vector<int> data(a, a + n);
	//cout << bb::InversePairs(data);
	int *b = dd::mergeSort(a,n);
	copy(b, b + n, ostream_iterator<int>(cout, " "));
}