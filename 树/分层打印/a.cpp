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
//last ���ڴ�ӡ�ĵ�ǰ�е����ҽڵ�    nlast ��һ�е����ҽڵ�
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