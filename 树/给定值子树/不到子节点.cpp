#include<iostream>
#include<vector>
#include<stack>
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
vector<vector<int> > has(TreeNode* root, int expectNumber, int sum, vector<vector<int> > ivector, vector<int> temp) {
	if (root == NULL)
		return ivector;
	sum += root->val;
	temp.push_back(root->val);
	if (sum == expectNumber)	
		ivector.push_back(temp);
	else if(root->left==NULL && root->right==NULL)  
	{
		sum -= temp.back();
		temp.pop_back();
	}
	else {
		ivector = has(root->left, expectNumber, sum, ivector, temp);
		ivector = has(root->right, expectNumber, sum, ivector, temp);
	}	
	return ivector;
}
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int> >ivector;
	vector<int> temp;
	int sum = 0;
	return has(root, expectNumber, sum, ivector, temp);
}

void main()
{
	TreeNode*p;
	CreateBiTree(p);
	int res;
	cout << "路径值" << endl;
	cin >> res;
	vector<vector<int> >ivector = FindPath(p, res);
	int n = ivector.size();
	for (int i = 0; i < n; ++i) {
		for (vector<int>::iterator it = ivector[i].begin(); it != ivector[i].end(); ++it)
			cout << *it << "   ";
		cout << endl;
	}
}