#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
//flag_1 标志  单左子节点 是否出现
//flag_2 标志  叶节点     是否出现
	bool chk(TreeNode* root) {
		if (root == NULL)
			return true;
		queue<TreeNode*>iqueue;
		iqueue.push(root);
		int flag_1 = 0;
		int flag_2 = 0;
		TreeNode* cur= iqueue.front();
		while (iqueue.size()>0) {
			cur = iqueue.front();
			iqueue.pop();
			if (flag_2) {//叶节点出现后，其余都是叶节点
				if (cur->left || cur->right)
					return false;
			}
			if (cur->left == NULL && cur->right == NULL)//判断是否为叶节点
				flag_2 = 1;
			else {//非叶节点
				if (cur->left == NULL && cur->right != NULL)//有单右子节点
					return false;
				else if (cur->left != NULL && cur->right == NULL) {//有单左子节点
					if (flag_1 == 1)//单左子节点只能出现一次
						return false;
					flag_1 = 1;
				}
				if (cur->left != NULL)
					iqueue.push(cur->left);
				if (cur->right != NULL)
					iqueue.push(cur->right);
			}	
		}
		return true;
	}

	void main() {
		TreeNode* p;
		CreateBiTree(p);
		if (chk(p))
			cout << "1";
		else
			cout << "0";
	}