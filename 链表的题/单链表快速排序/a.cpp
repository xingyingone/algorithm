#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node* next;
	Node(int nKey, Node* pNext)
		: key(nKey)
		, next(pNext)
	{}
};
typedef Node bnode;

Node* GetPartion(Node* pBegin, Node* pEnd)
{
	int key = pBegin->key;
	Node* p = pBegin;
	Node* q = p->next;

	while (q != pEnd)
	{
		if (q->key < key)
		{
			p = p->next;
			swap(p->key, q->key);
		}

		q = q->next;
	}
	swap(p->key, pBegin->key);
	return p;
}

void QuickSort(Node* pBeign, Node* pEnd)
{
	if (pBeign != pEnd)
	{
		Node* partion = GetPartion(pBeign, pEnd);
		QuickSort(pBeign, partion);
		QuickSort(partion->next, pEnd);
	}
}
void push(bnode** node, int m) {
	bnode* temp = new bnode(m, NULL);
	temp->next = *node;
	*node = temp;
}
void printList(bnode* res) {
	while (res != NULL) {
		cout << res->key << "  ";
		res = res->next;
	}
	cout << endl;
}
void main()
{
	bnode* res = NULL;
	bnode* a = NULL;

	/*Let us create two sorted linked lists to test the functions
	Created lists shall be a:5->10->15, b:2->3->20 */

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);
	QuickSort(a, NULL);
	printList(a);
}