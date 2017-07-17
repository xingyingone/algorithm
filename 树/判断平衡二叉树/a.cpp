#include<iostream>
#include<algorithm>
using namespace std;
//���������  
class BiTNode {
public:
	//����  
	int data;
	//���Һ���ָ��  
	BiTNode *lchild, *rchild;
};
typedef BiTNode *BiTree;
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
		T = (BiTree)malloc(sizeof(BiTNode));
		//���ɸ����  
		T->data = data;
		//����������  
		cout << "������ " << endl;
		CreateBiTree(T->lchild);
		//����������  
		cout << "������ " << endl;
		CreateBiTree(T->rchild);
	}
	return 0;
}
int getheight(BiTree root, int level) {
	if (root == NULL)
		return level;
	int left_height = getheight(root->lchild, level + 1);
	int right_height = getheight(root->rchild, level + 1);
	if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
		return -1;
	return max(left_height, right_height);
}
bool check(BiTree root) {
	cout << getheight(root, 0) << endl;
	return getheight(root, 0) == -1 ? false : true;
}
void main()
{
	BiTree p;
	CreateBiTree(p);
	if (check(p))
		cout << "1";
	else
		cout << "0";
}