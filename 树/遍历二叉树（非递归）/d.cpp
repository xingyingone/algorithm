#include<iostream>
#include<vector>
#include<stack>
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
vector<int>preorder(TreeNode* root) {
	vector<int>temp;
	if (root == NULL)
		return temp;
	TreeNode* cur = root;
	stack<TreeNode*>istack;
	istack.push(cur);
	while (istack.size() > 0) {
		cur = istack.top();
		temp.push_back(cur->val);
		istack.pop();
		if (cur->right != NULL)
			istack.push(cur->right);
		if (cur->left != NULL)
			istack.push(cur->left);
	}
	return temp;
}
vector<int>inorder(TreeNode* root) {
	vector<int>temp;
	if (root == NULL)
		return temp;
	TreeNode* cur = root;
	stack<TreeNode*>istack;
	while (istack.size()>0 || cur!=NULL) {
		while (cur != NULL) {
			istack.push(cur);
			cur = cur->left;
		}
		while (cur == NULL && istack.size() >0) {
			cur = istack.top();
			temp.push_back(cur->val);
			cur = cur->right;
			istack.pop();
		}
	}
	return temp;
}
vector<int>postorder(TreeNode* root) {
	vector<int>temp;
	if (root == NULL)
		return temp;
	stack<TreeNode*>istack;
	TreeNode*h = root;	//最近一次弹出并打印的节点
	TreeNode*c = root;	//stack栈顶节点
	istack.push(root);
	while (istack.size() > 0) {
		c = istack.top();
		if (c->left != NULL && h != c->left && h != c->right)
			istack.push(c->left);
		else if(c->right!=NULL && h!=c->right)
			istack.push(c->right);
		else {
			temp.push_back(istack.top()->val);
			istack.pop();
			h = c;
		}
	}
	return temp;
}
vector<vector<int> > convert(TreeNode* root) {
	vector<vector<int> >ivector;
	ivector.push_back(preorder(root));
	ivector.push_back(inorder(root));
	ivector.push_back(postorder(root));
	return ivector;
}
void main()
{
	BiTree T;
	CreateBiTree(T);
	vector<vector<int> >ivector = convert(T);
	for (vector<int>::iterator it = ivector[0].begin(); it != ivector[0].end(); ++it)
		cout << *it << "  ";
	cout << endl;
	for (vector<int>::iterator it = ivector[1].begin(); it != ivector[1].end(); ++it)
		cout << *it << "  ";
	cout << endl;
	for (vector<int>::iterator it = ivector[2].begin(); it != ivector[2].end(); ++it)
		cout << *it << "  ";
	cout << endl;
}