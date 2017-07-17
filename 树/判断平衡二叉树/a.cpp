#include<iostream>
#include<algorithm>
using namespace std;
//二叉树结点  
class BiTNode {
public:
	//数据  
	int data;
	//左右孩子指针  
	BiTNode *lchild, *rchild;
};
typedef BiTNode *BiTree;
//按先序序列创建二叉树  
int CreateBiTree(BiTree &T)
{
	int data;
	/*cout<<"开始 "<<endl;*/
	//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树  
	cin >> data;
	if (data == 0)
	{
		T = NULL;
		cout << "结束 " << endl;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		//生成根结点  
		T->data = data;
		//构造左子树  
		cout << "左子树 " << endl;
		CreateBiTree(T->lchild);
		//构造右子树  
		cout << "右子树 " << endl;
		CreateBiTree(T->rchild);
	}
	return 0;
}
int getheight(BiTree root, int level) {
	if (root == NULL)
		return level;
	int left_height = getheight(root->lchild, level + 1);
	int right_height = getheight(root->rchild, level + 1);
	if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
		return -1;
	return max(left_height, right_height);
}
bool check(BiTree root) {
	cout << getheight(root, 0) << endl;
	return getheight(root, 0) == -1 ? false : true;
}
void main()
{
	BiTree p;
	CreateBiTree(p);
	if (check(p))
		cout << "1";
	else
		cout << "0";
}