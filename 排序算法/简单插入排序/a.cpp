#include <iostream>
using namespace std;
void insertsort(int a[],int n);
int main()
{
	int a[]={1,3,8989,344,63,5,2,66};
	int n=sizeof(a)/sizeof(a[0]);
	insertsort(a,n);
	return 0;
}

void insertsort( int a[],int n )
{
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>=0&&(a[j]<a[j-1]);j--)
		{
			int temp;
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
		}
    }
	for (int i=0;i<=n-1;i++)
	{
		cout<<a[i]<<"  ";
	}
}