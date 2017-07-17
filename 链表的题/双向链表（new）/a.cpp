#include <iostream>
/*c++实现双链表的基本操作*/
using namespace std;
typedef struct student
{
        int data;
        struct student *pre;
        struct student *next;
}dnode;
//创立链表 
dnode *creat()
{
      dnode *head,*p,*s;
      int x,cycle=1;
      head=(dnode *)malloc(sizeof(dnode));
      p=head;
      while(cycle)
      {
        cout<<"please input the data!"<<endl;
        cin>>x;
        if(x!=0)
        {
			s=(dnode *)malloc(sizeof(dnode));
			s->data=x;
			p->next=s;
			s->pre=p;
			p=s;
        }
        else
        cycle=0;
      }
      head=head->next;
      head->pre=NULL;
      p->next=NULL;
      return head;
}
//打印链表 
void print(dnode *head)
{
     dnode *p,*s;
     p=head;
     cout<<"正序打印双链表:"<<endl; 
     while(p->next!=NULL)
     {
           cout<<p->data<<" ";
           p=p->next;
     }
     cout<<p->data<<endl;
     cout<<"逆序打印双链表:"<<endl;
     while(p->pre!=NULL)
     {
            cout<<p->data<<" ";
            p=p->pre;
     }               
     cout<<p->data<<endl; 
     
}
//双链表插入节点
dnode *insert(dnode *head,int num)
{
      dnode *p0,*p1;
      p1=head;
      p0=(dnode *)malloc(sizeof(dnode));
      p0->data=num;
      while(p0->data>p1->data&&p1->next!=NULL)
      {
            p1=p1->next;
      }
      if(p0->data<=p1->data)
      {
             if(head==p1)
             {
                         p0->next=p1;
                         p1->pre=p0;
                         head=p0;
             }
             else
             {
                 p1->pre->next=p0;
                 p0->next=p1;
                 p0->pre=p1->pre;
                 p1->pre=p0;
             }
      }
      else
      {
          p1->next=p0;
          p0->pre=p1;
          p0->next=NULL;
      }
      return head;
} 
//删除指定的节点
dnode *del(dnode *head,int num)
{
      dnode *p1,*p2;
      p1=head;
      while(num!=p1->data&&p1->next!=NULL)
       p1=p1->next;
      if(num==p1->data)
      {
                      if(p1==head)
                      {
                                  head=head->next;
                                  head->pre=NULL;
                                  free(p1);
                      } 
                      else if(p1->next==NULL)
                      {
                                  p1->pre->next=NULL;
                                  free(p1);
                      }
                      else
                      {
                                  p1->next->pre=p1->pre;
                                  p1->pre->next=p1->next;
                                  free(p1);           
                      }
      }
      else
      {
          cout<<"没有指定的节点"<<endl;
      }
      return head;
} 
int main(int argc, char *argv[])
{
    int x;
    dnode *head=creat();
    print(head);
    cout<<"输入要插入的数字:"<<endl;
    cin>>x;
    head=insert(head,x);
    print(head);
    cout<<"输入要删除的数字:"<<endl;
    cin>>x;
    head=del(head,x);
    print(head);
	return 0;
}