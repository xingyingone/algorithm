#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
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
	RandomListNode* p=pHead;
	unordered_map<RandomListNode*, RandomListNode*>imap;
	imap[NULL] = NULL;
	while (p!=NULL)
	{
		RandomListNode* temp = new RandomListNode(p->label);
		temp->next = NULL;
		temp->random = NULL;
		imap.insert(make_pair(p,temp));
		p = p->next;
	}
	p = pHead;
	while (p != NULL) {
		imap[p]->next = imap.find(p->next)->second;
		imap[p]->random = imap.find(p->random)->second;
		p = p->next;
	}
	return imap[pHead];
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