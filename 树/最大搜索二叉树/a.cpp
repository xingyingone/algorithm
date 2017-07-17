#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//���������  
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
//���������д���������  
int CreateBiTree(BiTree &T)
{
	int data;
	/*cout<<"��ʼ "<<endl;*/
	//�������������������н���ֵ��һ���ַ�������#����ʾ����  
	cin >> data;
	if (data == 0)
	{
		T = NULL;
		cout << "���� " << endl;
	}
	else
	{
		T = (BiTree)malloc(sizeof(TreeNode));
		//���ɸ����  
		T->val = data;
		//����������  
		cout << "������ " << endl;
		CreateBiTree(T->left);
		//����������  
		cout << "������ " << endl;
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
	a[0] = max(ln, rn);//�����������һ��ģ���ô���ֵ ��Сֵ�������вο�����
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