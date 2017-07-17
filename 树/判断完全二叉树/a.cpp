#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
//flag_1 ��־  �����ӽڵ� �Ƿ����
//flag_2 ��־  Ҷ�ڵ�     �Ƿ����
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
			if (flag_2) {//Ҷ�ڵ���ֺ����඼��Ҷ�ڵ�
				if (cur->left || cur->right)
					return false;
			}
			if (cur->left == NULL && cur->right == NULL)//�ж��Ƿ�ΪҶ�ڵ�
				flag_2 = 1;
			else {//��Ҷ�ڵ�
				if (cur->left == NULL && cur->right != NULL)//�е����ӽڵ�
					return false;
				else if (cur->left != NULL && cur->right == NULL) {//�е����ӽڵ�
					if (flag_1 == 1)//�����ӽڵ�ֻ�ܳ���һ��
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