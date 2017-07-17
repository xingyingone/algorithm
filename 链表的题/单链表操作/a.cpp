#include<iostream>
using namespace std;
typedef struct node
{
int data;
node*next;
}node;

node*create( )
{
	int static i=0;
	node*head,*rear,*p;
	int x=0;
	head=(node*)malloc(sizeof(node));
	while(1)
	{
		cout<<"请输出数据： ";
		cin>>x;
		if(x==0)
			break;
		p=(node*)malloc(sizeof(node));
		p->data=x;
		if(++i==1)
		{
			head->next=p;
		}
		else
		{
			rear->next=p;
		}
		rear=p;
	}
	rear->next=NULL;
	return head;
}
void print(node*head)
{
	node*p=head->next;
	if(head->next==NULL)
	{
	cout<<"空链表"<<endl;
	return;
	}
	while(p!=NULL)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
}
node *reverse(node*head)
{
	node *p,*q,*r;
	if(head->next==NULL)
	{
	return head;
	}
	p=head->next;
	q=p->next;
	p->next=NULL;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	head->next=p;
	print(head);
	return head;
}

node *sort()
{
	node *head,*New,*cur,*pre;
	head=(node*)malloc(sizeof(node));
	head->next =NULL;
	int cyc = 1,data;
	while (cyc)
	{
		cout<<"请输入"<<endl;
		cin>>data;
		if (data != 0)
		{
			New=(node*)malloc(sizeof(node));
			New->data = data;
			New->next = NULL;
			if (head->next == NULL)
			{
				head->next = New;
				continue;
			} 
			else if(New->data <= head->next->data)
			{
				New->next = head->next;
				head->next = New;
				continue;
			}
			cur = head->next;
			while(New->data > cur->data && cur->next !=NULL)
			{
				pre = cur;
				cur = cur->next;
			}
			if (cur->data >= New->data)
			{
				pre->next = New;
				New->next = cur;
			} 
			else
			{
				cur->next = New;
			}
		} 
		else
		{
			cyc = 0;
		}
	}
	print(head);
	return head;
}
void main()
{
node*head;
cout<<"创建列表"<<endl;
head = create( );
cout<<"打印列表"<<endl;
print(head);
cout<<"反转列表"<<endl;
head = reverse(head);
cout<<"正向排序"<<endl;
head = sort();

}
