#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
typedef TreeNode *BiTree;
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
		T = (BiTree)malloc(sizeof(TreeNode));
		//生成根结点  
		T->val = data;
		//构造左子树  
		cout << "左子树 " << endl;
		CreateBiTree(T->left);
		//构造右子树  
		cout << "右子树 " << endl;
		CreateBiTree(T->right);
	}
	return 0;
}
int Max(int a,int b,int c)
{
	if (a < b)
		return b < c ? c : b;
	else
		return a < c ? c : b;
}
int findMaxpath(BiTree &root, int& max)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftmax = findMaxpath(root->left,max);
	int rightmax = findMaxpath(root->right, max);
	int allmax = leftmax + rightmax + root->val;
	max = Max(leftmax, rightmax, allmax) > max ? Max(leftmax, rightmax, allmax) : max;
	return (leftmax > rightmax ? leftmax : rightmax) + root->val;
}
int findpath(BiTree &T)
{
	int max = INT_MIN;
	findMaxpath(T,max);
	return max;
}
void main()
{
	BiTree p;
	CreateBiTree(p);
	cout << findpath(p);
}