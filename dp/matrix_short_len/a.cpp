#include<iostream>
using namespace std;
int get_len(int *a,int m){
	int **b=new int*[m];
	int i,j;
	for(i=0;i<m;++i)
		b[i]=new int[m];
	b[0][0]=a[0];
	for(j=1;j<m;++j)
		b[0][j]=b[0][j-1]+a[j];
	for(i=1;i<m;++i)
		b[i][0]=b[i-1][0]+a[i*m];
	for(i=1;i<m;++i){
		for(j=1;j<m;++j){
			b[i][j]=min(b[i-1][j],b[i][j-1])+a[i*m+j];
		}
	}
	return b[m-1][m-1];
}
int main(){
	int a[]={   	1,3,5,9,
			8,1,3,4,
			5,0,6,1,
			8,8,4,0};
	int m=4;
	cout<<get_len(a,m)<<endl;
	return 0;
}