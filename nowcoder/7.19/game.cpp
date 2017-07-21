#include<iostream>
using namespace std;
namespace baoli
{
	int get_s(int*arr,int start,int end);
	int get_f(int*arr,int start,int end)
	{
		if(start==end)
			return arr[start];
		else
			return max(arr[start]+get_s(arr,start+1,end),arr[end]+get_s(arr,start,end-1));
	}
	int get_s(int*arr,int start,int end)
	{
		if(start==end)
			return 0;
		else
			return min(get_f(arr,start+1,end),get_f(arr,start,end-1));
	}
}
//两张表
namespace dp1
{
	int get(int*arr,int n)
	{
		int f[n][n];
		int s[n][n];
		for(int i=0;i<n;++i)
		{
			f[i][i]=arr[i];
			s[i][i]=0;
		}
		for(int t=1;t<n;t+=1)
		{
			for(int i=0;i<n-t;++i)
			{
				f[i][i+t]=max(arr[i]+s[i+1][i+t],arr[i+t]+s[i][i+t-1]);
				s[i][i+t]=min(f[i+1][i+t],f[i][i+t-1]);
			}
		}
		return max(f[0][n-1],s[0][n-1]);
	}
}
//一张表
namespace dp2
{
	int get(int*arr,int n)
	{
		int j;
		int f[n][n];
		for(int i=0;i<n;++i)
			f[i][i]=arr[i];
		for(int i=0;i<n-1;++i)
			f[i][i+1]=max(arr[i],arr[i+1]);
		for(int t=2;t<n;++t)   //t表示要第一次的横坐标
		{
			for(int i=0;i<n-t;++i)
			{
				j=i+t;
				f[i][j]=max(arr[i]+min(f[i+2][j],f[i+1][j-1]),
					       arr[j]+min(f[i+1][j-1],f[i][j-2]));
			}
		}
		return f[0][n-1];
	}

}
int main()
{
	int arr[]={1,2,33,4,4};
	int n=sizeof(arr)/sizeof(int);
	int sum=0,first=0;
	for(auto i:arr)
		sum+=i;
	{
		using namespace baoli;
		first=get_f(arr,0,n-1);
		cout<<max(first,sum-first)<<endl;
	}
	{
		using namespace dp1;
		cout<<get(arr,n)<<endl;
	}
	{
		using namespace dp2;
		int first=get(arr,n);
		cout<<max(first,sum-first)<<endl;
	}
	return 0;
}