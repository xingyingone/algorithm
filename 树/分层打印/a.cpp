#include<iostream>
#include<vector>
#include<queue>
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
//last 正在打印的当前行的最右节点    nlast 下一行的最右节点
vector<vector<int> > printTree(TreeNode* root) {
	// write code here
	vector<vector<int> >ivector;
	queue<TreeNode*>iqueue;
	iqueue.push(root);
	TreeNode* last=root, *nlast=root;
	vector<int>temp;
	while (iqueue.size() != 0) {
		if (iqueue.front()->left != NULL)
			iqueue.push(iqueue.front()->left);
		if (iqueue.front()->right != NULL)
			iqueue.push(iqueue.front()->right);
		nlast = iqueue.back();
		temp.push_back(iqueue.front()->val);
		if (iqueue.front() == last) {
			ivector.push_back(temp);
			temp.clear();
			last = nlast;
		}
		iqueue.pop();	
	}
	return ivector;
}
void main()
{
	BiTree p;
	CreateBiTree(p);
	vector<vector<int> >ivector;
	ivector = printTree(p);
	for (int i = 0; i <= 2; i++) {
		for (vector<int>::iterator it = ivector[i].begin(); it != ivector[i].end(); ++it)
			cout << *it << "   ";
		cout << endl;
	}
}