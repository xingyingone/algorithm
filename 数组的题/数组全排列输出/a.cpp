#include<iostream>
#include<iterator>
using namespace std;
int t = 0;
template<typename T> void Swap(T &A, T &B)
{
	T Tmp = A;
	A = B;
	B = Tmp;
}

//���ظ�Ԫ�غ����������[Begin,End)֮����Ԫ�غ͵�EndԪ����ȣ���ִ�н���Begin��EndԪ�أ�
//��Ϊ���������뽻��Begin��End֮ǰ��EndԪ����ͬ��Ԫ�ز����Ľ��һ��
template<typename T> bool IsSwap(T A[], int Begin, int End)
{
	while (Begin<End)
	{
		if (A[Begin] == A[End])
			return false;
		Begin++;
	}
	return true;
}

template<typename T> void Permutation(T A[], int Begin, int N)
{
	if (Begin == N){
		cout << "  ���  :";
		copy(A, A + N, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	else{
		for (int i = Begin; i != N; i++){
			if (IsSwap(A, Begin, i)){
				Swap(A[i], A[Begin]);     //���õ�i��Ԫ�غͿ�ʼ�ĵ�Begin��Ԫ�ػ���
				cout << " %%% "<<t<<"  ����ǰ �� ";
				copy(A, A + N, ostream_iterator<int>(cout, " "));
				Permutation(A, Begin + 1, N);//Ȼ��������Begin+1��END��Ԫ�ص�ȫ���У������
				Swap(A[Begin], A[i]);     //�ٻָ���i��Ԫ�غͿ�ʼ�ĵ�Begin��Ԫ��
				cout << " %%% "<<t<<"  ������ �� ";
				copy(A, A + N, ostream_iterator<int>(cout, " "));
				cout << endl;
				t++;
			}
		}
	}
	return;
}

int main()
{
	int A[5] = { 1,2,3 };
	int N = 3;
	Permutation(A, 0, N);
	return 0;
}