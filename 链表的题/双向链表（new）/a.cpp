#include <iostream>
/*c++ʵ��˫����Ļ�������*/
using namespace std;
typedef struct student
{
        int data;
        struct student *pre;
        struct student *next;
}dnode;
//�������� 
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
//��ӡ���� 
void print(dnode *head)
{
     dnode *p,*s;
     p=head;
     cout<<"�����ӡ˫����:"<<endl; 
     while(p->next!=NULL)
     {
           cout<<p->data<<" ";
           p=p->next;
     }
     cout<<p->data<<endl;
     cout<<"�����ӡ˫����:"<<endl;
     while(p->pre!=NULL)
     {
            cout<<p->data<<" ";
            p=p->pre;
     }               
     cout<<p->data<<endl; 
     
}
//˫�������ڵ�
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
//ɾ��ָ���Ľڵ�
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
          cout<<"û��ָ���Ľڵ�"<<endl;
      }
      return head;
} 
int main(int argc, char *argv[])
{
    int x;
    dnode *head=creat();
    print(head);
    cout<<"����Ҫ���������:"<<endl;
    cin>>x;
    head=insert(head,x);
    print(head);
    cout<<"����Ҫɾ��������:"<<endl;
    cin>>x;
    head=del(head,x);
    print(head);
	return 0;
}