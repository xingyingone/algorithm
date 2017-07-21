/*
最长有效括号长度
*/

#include<iostream>
#include<string>
using namespace std;
void fun(string str)
{
	int n=str.size();
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;++i)
	{
		if(str[i]=='(')
			dp[i]=0;
		else
			{
				if(str[i-dp[i-1]-1]==')')
					dp[i]=0;
				else
				{
					if(i-dp[i-1]-2>=0 && str[i-dp[i-1]-2]==')')
						dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];//	 ( )  (  )
					else
						dp[i]=dp[i-1]+2;		// (  ( ( ) )
				}				
			}
	}
	for(int i=0;i<n;++i){
		cout<<str[i]<<"   "<<dp[i]<<"   ";
	cout<<endl;
	}
		
}
int main()
{
	string str = "(())(()()";
	fun(str);
	return 0;
}