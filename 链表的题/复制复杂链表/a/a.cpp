#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	RandomListNode*p = pHead;
	while (p != NULL) {
		RandomListNode *temp = new RandomListNode(p->label);
		temp->next = p->next;
		p->next = temp;
		p = p->next->next;
	}
	p = pHead;
	while (p != NULL) {
		if (p->random != NULL)
			p->next->random = p->random->next;
		else
			p->next->random = NULL;
		p = p->next->next;
	}
	RandomListNode *pCloneHead, *pClonenode;
	pCloneHead = pClonenode = pHead->next, p = pHead;
	if (pClonenode != NULL && pClonenode->next != NULL) {
		while (pClonenode->next != NULL) {
			p->next = pClonenode->next;
			pClonenode->next = p->next->next;
			p = p->next;
			pClonenode = pClonenode->next;
		}
	}
	p->next = NULL;
	return pCloneHead;
}
void main() {
	RandomListNode p(1);
	RandomListNode q(2);
	RandomListNode r(3);
	RandomListNode s(4);
	RandomListNode t(5);
	p.next = &q;
	p.random = &r;

	q.next = &r;
	q.random = &t;

	r.next = &s;
	r.random = NULL;

	s.next = &t;
	s.random = &q;

	t.next = NULL;
	t.random = NULL;

	RandomListNode*pp = Clone(&p);
	while (pp != NULL) {
		cout << pp->label << "   ";
		if (pp->random != NULL)
			cout << pp->random->label << "   ";
		pp = pp->next;
		cout << endl;
	}
}