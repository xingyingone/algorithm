#include<iostream>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
struct ListNode {
	int label;
	struct ListNode *next;
	ListNode(int x) :
		label(x), next(NULL){
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
namespace aa {
	bool isfun(BiTree root, BiTree a) {
		if (root == NULL)
			return false;
		if (root == a)
			return true;
		bool flag = isfun(root->left, a);
		if (!flag)
			flag = isfun(root->right, a);
		return flag;
	}
	void fun(BiTree root, BiTree a, BiTree b, BiTree& res) {
		if (root == NULL || a == NULL || b == NULL)
			return;
		bool flag = isfun(root, a) && isfun(root, b);
		if (flag) {
			res = root;
			fun(res->left, a, b, res);
			fun(res->right, a, b, res);
		}
	}
}
namespace bb {
	bool getlist(BiTree root, BiTree T, list<BiTree>&ilist) {
		if (T == NULL) {
			return false;
		}		
		if (root == NULL) {
			return false;
		}
		ilist.push_front(root);
		if (root == T) 	
			return true;	
		bool flag=getlist(root->left, T, ilist);
		if (!flag) {
			flag = getlist(root->right, T, ilist);
			if (!flag && ilist.size() > 0)
				ilist.pop_front();
		}	
		return flag;
	}
	void getnode(list<BiTree>list1, list<BiTree>list2, BiTree& res) {
		if (list1.size() == 0 || list2.size() == 0)
			return;
		int n = list1.size() - list2.size();
		list<BiTree>::iterator it1 = list1.begin();
		list<BiTree>::iterator it2 = list2.begin();
		if (n > 0)
			advance(it1, n);
		else
			advance(it2, -n);
		while (it1 != list1.end() && it2 != list2.end() && *it1 != *it2) {
			++it1;
			++it2;
		}
		if (it1 != list1.end() && it2 != list2.end()&&*it1 == *it2) {
			res = *it1;
		}
	}
}
int main()
{
	//{
	//	using namespace aa;	
	//	BiTree T;
	//	CreateBiTree(T);
	//	BiTree res = NULL;
	//	fun(T, T->left, T->right, res);
	//	if (res)
	//		cout << res->val;
	//	else
	//		cout << 0;
	//}
	{
		using namespace bb;
		BiTree T;
		CreateBiTree(T);
		list<BiTree>list1;
		list<BiTree>list2;
		BiTree res = NULL;
		if (!getlist(T, T->left, list1))
			cout << 0;
		if(!getlist(T, T->right, list2))
			cout << 0;
		getnode(list1, list2, res);
		if (res)
			cout << res->val;
		else
			cout << 0;
	}
	return 0;
}