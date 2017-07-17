#include<iostream>
using namespace std;
//���������  
class BiTNode{ 
public:
    //����  
    char data;  
    //���Һ���ָ��  
    BiTNode *lchild,*rchild;  
};  
typedef BiTNode *BiTree;
//���������д���������  
int CreateBiTree(BiTree &T)
{  
    char data;  
	/*cout<<"��ʼ "<<endl;*/
    //�������������������н���ֵ��һ���ַ�������#����ʾ����  
   cin>>data;
    if(data == '#')
	{  
        T = NULL;  
		cout<<"���� "<<endl;
    }  
    else
	{  
        T = (BiTree)malloc(sizeof(BiTNode));  
        //���ɸ����  
        T->data = data;  
        //����������  
	cout<<"������ "<<endl;
        CreateBiTree(T->lchild);  
        //����������  
	cout<<"������ "<<endl;
        CreateBiTree(T->rchild);  
    }  
    return 0;  
}  
//���  
	void Visit(BiTree T)
	{  
	if(T->data != '#')
	{  
		cout<<T->data; 
	}  
	}  
//�������  
void PreOrder(BiTree T){  
    if(T != NULL){  
        //���ʸ��ڵ�  
        Visit(T);  
        //�������ӽ��  
        PreOrder(T->lchild);  
        //�������ӽ��  
        PreOrder(T->rchild);  
    }  
}  
//�������  
void InOrder(BiTree T){  
    if(T != NULL){  
        //�������ӽ��  
        InOrder(T->lchild);  
        //���ʸ��ڵ�  
        Visit(T);  
        //�������ӽ��  
        InOrder(T->rchild);  
    }  
}  
//�������  
void PostOrder(BiTree T){  
    if(T != NULL){  
        //�������ӽ��  
        PostOrder(T->lchild);  
        //�������ӽ��  
        PostOrder(T->rchild);  
        //���ʸ��ڵ�  
        Visit(T);  
    }  
}  
void main()
{
	BiTree p;
	CreateBiTree(p);
	PostOrder(p);
}