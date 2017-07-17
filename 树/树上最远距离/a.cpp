#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
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
/*
int findLongest(TreeNode* root) {
	static int a;
	if (root == NULL) {
		a = 0;
		return 0;
	}
	int lmax = findLongest(root->left);
	int maxfromleft = a;
	int rmax = findLongest(root->right);
	int maxfromright = a;
	int curmax = maxfromleft + maxfromright + 1;
	a = max(maxfromleft, maxfromright) + 1;
	return max(max(lmax, rmax), curmax);
}*/

  int getmax(TreeNode* root,int &res) {
        if (root == NULL) {
            return 0;
        }
        int left_height = getmax(root->left,res);
        int right_height = getmax(root->right,res);
        res = max(left_height + right_height + 1, res);
        return max(left_height, right_height) + 1;
    }
    int findLongest(TreeNode* root) {
        if (root == NULL)
            return 0;
        int a=0;
        getmax(root,a);
        return a;
    }

void main()
{
	BiTree p;
	CreateBiTree(p);
	cout << findLongest(p);
}