#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//二叉树结点  
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
typedef TreeNode *BiTree;
TreeNode* posorder(TreeNode* root, int* a);
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
static int a[3] = { 0,0,0 }; //a[0]:size   a[1]:min  a[2]:max
TreeNode* getMax(TreeNode* root) {
	// write code here
	
	if (root == NULL) {
		a[0] = 0;
		a[1] = INT_MAX;
		a[2] = INT_MIN;
		return NULL;
	}
	TreeNode* lBST = getMax(root->left);
	int ln = a[0];
	int lmin = a[1];
	int lmax = a[2];
	TreeNode* rBST = getMax(root->right);
	int rn = a[0];
	int rmin = a[1];
	int rmax = a[2];
	a[1] = min(lmin, root->val);
	a[2] = max(rmax, root->val);
	if (lBST == root->left && rBST == root->right && lmax<root->val && rmin>root->val) {
		a[0] = ln + rn + 1;
		return root;
	}
	a[0] = max(ln, rn);//如果不是连在一起的，那么最大值 最小值将不具有参考意义
	if (ln == rn)
		return lBST->val > rBST->val ? lBST : rBST;
	return ln>rn ? lBST : rBST;
}

void main()
{
	BiTree p;
	CreateBiTree(p);
	cout << getMax(p)->val;
	cout << a[0] << "  " << a[1] << "  " << a[2];
}