//aa bb Ϊ�����
//cc dd Ϊ�Լ�д�Ĺ鲢����
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
namespace aa{
	int InversePairCore(vector<int>& data, int*& copy, int start, int end);
		int InversePairs(vector<int> data) {
			if (data.size() <= 1) return 0;//������ڵ���1��Ԫ�أ�ֱ�ӷ���0
			int* copy = new int[data.size()];
			//��ʼ�������飬��������Ϊ�����ʱ����Ľ�������Ҫ������Ľ�����Ƶ�ԭ������
			for (unsigned int i = 0; i<data.size(); i++)
				copy[i] = 0;
			//���õݹ麯�������
			int count = InversePairCore(data, copy, 0, data.size() - 1);
			delete[] copy;//ɾ����ʱ����
			return count;
		}
		//��������庯��
		int InversePairCore(vector<int>& data, int*& copy, int start, int end)
		{
			if (start == end)
			{
				copy[start] = data[start];
				return 0;
			}
			//�������ֳ�������
			int length = (end - start) / 2;//����ʹ�õ��±귨������Ҫ�����������������Ҳ����ֱ��ʹ��mid=��start+end��/2
										   //�ֱ������߲��ֺ��ұ߲���
			int left = InversePairCore(data, copy, start, start + length) % 1000000007;
			int right = InversePairCore(data, copy, start + length + 1, end) % 1000000007;
			//�����������
			int i = start + length;//ǰһ����������һ���±�
			int j = end;//��һ��������±�
			int index = end;//���������±꣬�����һ������
			int count = 0;
			while (i >= start && j >= start + length + 1)
			{
				if (data[i]>data[j])
				{
					copy[index--] = data[i--];
					//ͳ�Ƴ���
					count += j - start - length;
					if (count >= 1000000007)//��ֵ��������
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
			//����
			for (int i = start; i <= end; i++) {
				data[i] = copy[i];
			}
			//�������յĽ��
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
			copy[start] = A[start];//��ֹcopy[start]δ����ʼ��
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