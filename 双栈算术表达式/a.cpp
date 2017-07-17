#include <iostream>
#include <string>
#include <stack>
using namespace std;
char symbol[] = "+-*/(";
char t[100];
int j=0;
int getSymbol(char c)
{
        int i;
        for(i=0; i<strlen(symbol); i++)
        {
                if(symbol[i]== c)
                        break;
        }
        return i;
}


int main(int argc, char* argv[])
{
        char exp[]="9+8";
        char *p=exp;

      
        stack<char> op;

        while(true)
        {
                if(isdigit(*p))
                {
					 int i=0;
					 while(isdigit(*p))
					 {
						 i = i*10+(*p-'0');
						 p++;
					 }
                       t[j]=i+'0'; j++; //dd
                        cout<<i<<endl;
                }

                if(*p==')')
                {
                        while(op.top()!='(')
						{t[j]=op.top();j++;//dd
                                cout<<op.top()<<endl;
                                op.pop();
                        }
                        op.pop();
                }
                else if(*p=='(')
                {
                        op.push('(');
                }
                else if(*p=='+'||*p=='-'||*p=='*'||*p=='/')
                {
                        while(!op.empty()&&getSymbol(*p)<=getSymbol(op.top()))
                        {
                                if(op.top()!='(')
								{t[j]=op.top();j++;//dd
                                        cout<<op.top()<<endl;
                                        op.pop();
                                }
                                else
                                        break;
                        }
                        op.push(*p);
                }
                else if(*p=='\0')
                        break;

                p++;
        }

        while(!op.empty())
		{t[j]=op.top();j++;//dd
                cout<<op.top()<<endl;
                op.pop();
        }
		t[j]='\0';

       while(!op.empty())
        {t[j]=op.top();j++;  //dd
                cout<<op.top()<<endl;
                op.pop();
        }
		t[j]='\0';
		cout<<"--------"<<endl;
		for(int i=0;i<j;i++)
			cout<<t[i]<<" "<<endl;


		stack<int>istack;
		for(int i=0;i<j;i++)
		{
			if(isdigit(t[i]))
			{
				istack.push(t[i]-'0');
			}
			else
			{
				int n1=istack.top();istack.pop();
				if(t[i]=='+')
				{
					int n2=istack.top();istack.pop();
					istack.push(n1+n2);
				}
				if(t[i]=='-')
				{
					int n2=istack.top();istack.pop();
					istack.push(n2-n1);
				}
				if(t[i]=='*')
				{
					int n2=istack.top();istack.pop();
					istack.push(n1*n2);
				}
				if(t[i]=='/')
				{
					int n2=istack.top();istack.pop();
					istack.push(n2/n1);
				}
			}
		}
		cout<<istack.size()<<endl;
		cout<<istack.top();
		return 0;
		}
		