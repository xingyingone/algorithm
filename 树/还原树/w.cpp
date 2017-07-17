#include<iostream>
#include<string>
#include<vector>
using namespace std;
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
 struct TreeNode* ConstructBinaryTree(vector<int> pre,int pstart,int pend,vector<int> in,int istart,int iend) {
	 TreeNode*root = new TreeNode(pre[pstart]);
	 root->left = NULL;
	 root->right = NULL;
	 int i = istart;
	 while (i <= iend ) {
		 if (pre[pstart] == in[i])
			 break;
		 ++i;
	 }
	 int leftLength = i - istart;
	 int rightLength = iend - i;
	 if(leftLength>0)
		 root->left = ConstructBinaryTree(pre, pstart + 1, pstart+ leftLength, in, istart, i - 1);     //◊Û∞Î±ﬂ
	 if(rightLength>0)
		 root->right = ConstructBinaryTree(pre, pstart + leftLength + 1, pend, in, i + 1, iend);        //”“∞Î±ﬂ
	 return root;
 }
 struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	 if (pre.size() != in.size() || pre.size() == 0)
		 return NULL;
	 return ConstructBinaryTree(pre,0,pre.size()-1,in,0,in.size()-1);
 }
 void preorder(struct TreeNode*p) {
	 if (p == NULL)
		 return;
	 else
		 cout << p->val;
	 preorder(p->left);
	 preorder(p->right);
 }
void main() {
	int a[] = { 1,2,4,7,3,5,6,8 };
	int b[] = { 4,7,2,1,5,3,8,6 };
	int n = sizeof(a) / sizeof(int);
	vector<int> pre;
	vector<int> in;
	for (int i = 0; i < n; ++i) {
		pre.push_back(a[i]);
		in.push_back(b[i]);
	}
	struct TreeNode* p = reConstructBinaryTree(pre, in);
	preorder(p);
	//cout << p->val;
}