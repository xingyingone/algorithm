#include<iostream>
#include<string.h>
using namespace std;
int get(int n){
	int sum=0;
	while(n){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}
bool check(int threshold,int rows,int cols,bool*flag,int i,int j){
	if(i>=0 && i<rows && j>=0 && j<cols && flag[i*cols+j]==false&& get(i)+get(j)<=threshold)
		return true;
	return false;
}
int fun(int threshold,int rows,int cols,bool*flag,int i,int j){
	int index=i*cols+j;
	int count=0;
	if(check(threshold,rows,cols,flag,i,j)){
		flag[index]=true;
		count=1+fun(threshold,rows,cols,flag,i-1,j)+
		fun(threshold,rows,cols,flag,i,j-1)+
		fun(threshold,rows,cols,flag,i+1,j)+
		fun(threshold,rows,cols,flag,i,j+1);
	}
	return count;
}
 int movingCount(int threshold, int rows, int cols)
{
        	bool *flag=new bool[rows*cols];
        	memset(flag,false,rows*cols);
        	int count=fun(threshold,rows,cols,flag,0,0);
        	delete  []flag;
        	return  count;
}
int main(){
	cout<<movingCount(18,4,6)<<endl;
	return 0;
}