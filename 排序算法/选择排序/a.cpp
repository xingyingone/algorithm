#include<iostream>
using namespace std;
void select(int a[],int n);
void main()
{
	int a[9]={9,1,5,8,3,7,4,6,2};
	int n=(sizeof(a)/sizeof(a[0]));
	select(a,n);
}

void select(int a[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		if(i!=min)
		{int temp;
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;}
	}
	for(i=1;i<n;i++)
	{
	cout<<a[i]<<endl;
	}
}