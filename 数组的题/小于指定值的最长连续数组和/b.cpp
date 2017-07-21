#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int get(int*arr, int n,int obj){
	int low=0;
	int high=n-1;
	int mid=0;
	int res=-1;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]>=obj)
		{
			res=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return res;
}
int maxLengthAwesome(int*arr, int n, int k) {
	int * helpArr=new int[n+1];
	helpArr[0]=0;
	int sum=0;
	int res=0;
	for(int i=0;i<n;++i){
		sum+=arr[i];
		helpArr[i+1]=max(sum,helpArr[i]);
	}
	for(int i=0;i<n;++i)
		cout<<helpArr[i]<<"   ";
	cout<<endl;
	sum=0;
	int  pre=0;
	int len=0;
	for(int i=0;i<n;++i){
		sum+=arr[i];
		pre=get(helpArr,n+1,sum-k);
		len=pre==-1?0:i-pre+1;  //i为arr坐标，pre为helpArr坐标，所以要加一
		res=max(res,len);
	}
	return res;
}
int main() {
	//int a[] = { 1,2,-1,-3,8,1,1,1,-4,3,3 };
	int a[] = { 3,-2,-4,0,6};
	int n = sizeof(a) / sizeof(int);
	cout << maxLengthAwesome(a, n, -2)<<endl;
	return 0;
}