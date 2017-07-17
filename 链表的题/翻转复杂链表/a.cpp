#include<iostream>
#include<map>
using namespace std;
struct Node
{
	Node*p1;
	Node*p2;
	int data;
	Node(int d) :data(d), p1(NULL), p2(NULL){}
};
Node*reverse(Node* node)
{
	map<Node*, Node*>imap;
	Node* pre, *cur, *next;
	pre = node->p1;
	if (pre == NULL)
		return node;
	cur = pre->p1;
	pre->p1 = NULL;
	while (cur != NULL)
	{
		imap.insert(pair<Node*, Node*>(pre,pre->p2));
		next = cur->p1;
		cur->p1 = pre;
		pre = cur;
		cur = next;
	}
	node->p1 = pre;
	map<Node*, Node*>::iterator it;
	for (it = imap.begin(); it != imap.end(); ++it)
		it->second->p2 = it->first;
	return node;
}
void main()
{
	Node*head = new Node(0);
	Node* a = new Node(1);
	Node* b = new Node(2);
	Node* c = new Node(3);
	head->p1 = a;
	a->p1 = b;
	b->p1 = c;
	a->p2 = c;
	b->p2 = a;
	c->p2 = b;
	head = reverse(head);
	head = head->p1;
	while (head) {
		cout << head->data << "   " << head->p2->data << endl;
		head = head->p1;
	}
}