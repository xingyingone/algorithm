/*朴素匹配算法
#include<iostream>
#include<string>
using namespace std;
void index(string s,string t,int pos);
int main()
{
cout<<"请输入主字符串"<<endl;
string s;
getline(cin,s);
cout<<"请输入子字符串"<<endl;
string t;
getline(cin,t);
int pos;
cout<<"请输入在第多少位后开始匹配"<<endl;
cin>>pos;
index(s,t,pos);
return 0;
}

void index(string s,string t,int pos)
{
	int m=s.length();
	int n=t.length();
	int i=pos;
	int j=0;
	while(i<=m-1 && j<=n-1)
	{
	if(s[i]==t[j])
	{
	++i;
	++j;
	}
	else
	{
	i=i-j+1;
	j=0;
	}
	}
	if(j==n)
		cout<<"位置"<<" "<<i-n+1;
	else
		cout<<"没有";
}

*/

/*KMP算法*/



#include<iostream>
#include<string>
#include<vector>
using namespace std;
void getnext(string p,vector<int>next);
int main()
{
string s;
cout<<"请输入主字符串"<<endl;
getline(cin,s);
string p;
cout<<"请输入子字符串"<<endl;
getline(cin,p);

vector<int>next(p.size());
getnext(p,next);
cout<<"从第几位开始匹配"<<endl;
int pos;
cin>>pos;
int i=pos,j=0;
while(i!=s.length()&&j!=p.length())
	{
	if(j==-1||s[i]==p[j])
	{
	++i;
	++j;
	}
	else
		j=next[j];
	}

	if(j==p.length())
		cout<<"从第"<<i-j<<"位已经开始匹配";
	else
		cout<<"无匹配子序列";
	return 0;
}
void getnext(string p,vector<int>next)
{
	next[0]=-1;
	int i=0,j=-1;
	while(i!=p.size()-1)
	{
	if(j==-1||p[i]==p[j])
	{
	++i;
	++j;
	if(p[i]!=p[j])
	    next[i]=j;
	else
		next[i]=next[j];
	}
	else
		j=next[j];
	}
for(int i=0;i<p.size()-1;i++)
{
cout<<"输出next数组"<<endl;
cout<<next[i]<<" ";
cout<<endl;
}
}