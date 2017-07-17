#include<iostream>
using namespace std;
//二叉树结点  
class BiTNode{ 
public:
    //数据  
    char data;  
    //左右孩子指针  
    BiTNode *lchild,*rchild;  
};  
typedef BiTNode *BiTree;
//按先序序列创建二叉树  
int CreateBiTree(BiTree &T)
{  
    char data;  
	/*cout<<"开始 "<<endl;*/
    //按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树  
   cin>>data;
    if(data == '#')
	{  
        T = NULL;  
		cout<<"结束 "<<endl;
    }  
    else
	{  
        T = (BiTree)malloc(sizeof(BiTNode));  
        //生成根结点  
        T->data = data;  
        //构造左子树  
	cout<<"左子树 "<<endl;
        CreateBiTree(T->lchild);  
        //构造右子树  
	cout<<"右子树 "<<endl;
        CreateBiTree(T->rchild);  
    }  
    return 0;  
}  
//输出  
	void Visit(BiTree T)
	{  
	if(T->data != '#')
	{  
		cout<<T->data; 
	}  
	}  
//先序遍历  
void PreOrder(BiTree T){  
    if(T != NULL){  
        //访问根节点  
        Visit(T);  
        //访问左子结点  
        PreOrder(T->lchild);  
        //访问右子结点  
        PreOrder(T->rchild);  
    }  
}  
//中序遍历  
void InOrder(BiTree T){  
    if(T != NULL){  
        //访问左子结点  
        InOrder(T->lchild);  
        //访问根节点  
        Visit(T);  
        //访问右子结点  
        InOrder(T->rchild);  
    }  
}  
//后序遍历  
void PostOrder(BiTree T){  
    if(T != NULL){  
        //访问左子结点  
        PostOrder(T->lchild);  
        //访问右子结点  
        PostOrder(T->rchild);  
        //访问根节点  
        Visit(T);  
    }  
}  
void main()
{
	BiTree p;
	CreateBiTree(p);
	PostOrder(p);
}