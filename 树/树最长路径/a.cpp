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