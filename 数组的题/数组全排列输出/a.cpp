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

//判重复元素函数，如果第[Begin,End)之间有元素和第End元素相等，则不执行交换Begin和End元素，
//因为交换它两与交换Begin和End之前与End元素相同的元素产生的结果一致
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
		cout << "  结果  :";
		copy(A, A + N, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	else{
		for (int i = Begin; i != N; i++){
			if (IsSwap(A, Begin, i)){
				Swap(A[i], A[Begin]);     //先让第i个元素和开始的第Begin个元素互换
				cout << " %%% "<<t<<"  交换前 ： ";
				copy(A, A + N, ostream_iterator<int>(cout, " "));
				Permutation(A, Begin + 1, N);//然后求后面第Begin+1～END个元素的全排列，并输出
				Swap(A[Begin], A[i]);     //再恢复第i个元素和开始的第Begin个元素
				cout << " %%% "<<t<<"  交换后 ： ";
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