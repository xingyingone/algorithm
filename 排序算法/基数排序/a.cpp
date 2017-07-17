#include <iostream>
using namespace std;
int *radixsort(int *A,int n);
int find(int t,int n);
int main()
{
	int a[] = {3,22,40,21,444,9,42,11};
	int n = sizeof(a)/sizeof(int);
	radixsort(a,n);
	for (int i=0;i<=n-1;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

int * radixsort( int *A,int n )
{
	int max = A[0];  //最大值
	int mm = 0;  //最大值位数
	int byte = 1;//记录元素位数
	int m = 0;
	int *B = new int[n];
	for (int i=0;i<=n-1;i++)
	{
		B[i] = A[i];
		if (A[i]>max)
			max = A[i];
	}
	while(max)
	{
		max/=10; 
		mm++;
	}
	while(byte<=mm)
	{
		for (int i=0;i<10;i++)
		{
			for (int k=0;k<n;k++)
			{
				if(find(B[k],byte-1) == i)
					A[m++] = B[k];
			}
		}
		m = 0;
		byte++;
		for (int i=0;i<=n-1;i++)
			B[i] = A[i];
	}
	delete[]B;
	return A;
}

int find( int t,int n )
{
	for (int i=0;i<n;i++)
		t = t/10;
	t = t%10;
	return t;
}