/*一
#include<iostream>
#include<string>
using namespace std;
int strhui(int i,int j,string str,int length);
int main()
{
	string str;
	cout<<"请输入字符串"<<endl;
	getline(cin,str);
	int length=str.length();
	int i=0,j=length-1;
	int result=strhui( i, j, str, length);
	if(result==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

int strhui(int i,int j,string str,int length)
{
if(length==1||length==0)
{
return 1;
}
if(str[i]!=str[j])
	return 0;
return  strhui(i+1,j-1,str,length-2);
	 }
	 */

/*二
#include<iostream>
using namespace std;
bool huiwenchuan(char a[],int i,int j);
int main()
{
char a[255];
cin.getline(a,255);
int m=strlen(a);
int i=0,j=m-1;
bool t=huiwenchuan(a,i,j);
if(t==0)
	cout<<"no"<<endl;
if(t==1)
	cout<<"yes"<<endl;
return 0;
}

bool huiwenchuan(char a[],int i,int j)
{
if(i==j)
	return 1;
else
{
if(a[i]==a[j])
{
i++;
j--;
huiwenchuan(a,i,j);
}
else
	return 0;
}
}
*/

/*三
#include<iostream>
using namespace std;
void huiwen(char str[]);
int main()
{
char str[255];
cout<<"那就快输入吧"<<endl;
cin.getline(str,255);
huiwen(str);
return 0;
}

void huiwen(char str[])
{
int m=strlen(str);
bool flag=true;
for(int i=0;i<m/2;i++)
{
if(str[i]!=str[m-i-1])
{
flag=false;
break;
}
}
if(flag==false)
	cout<<"no"<<endl;
else
	cout<<"yes"<<endl;
}

*/
/*四*/
#include<iostream>
#include <stack>
int const N=100;
using namespace std;
void main()
{
 char c[N];
 stack<char> sk;
 int i,isHuiwen=1;
 for(i=0;i<N;i++)
 {
  cin>>c[i];
  if(c[i]=='@')
   break;
 }
 for(int j=0;j<=i-1;j++)
 {
  if(c[j]!='@')
   sk.push(c[j]);
 }
 for(i=0;i<N;i++)
 {
  if(c[i]=='@')
   break;
  if(c[i]!=sk.top())
  {
   isHuiwen = 0;
   break;
  }
  sk.pop();
 }
 
 if(isHuiwen)
 cout<<"yes"<<endl;
 else
 cout<<"no"<<endl;

}