#include<iostream>
using namespace std;
struct node {
	char a;
	node* next;
};
void Reverse(node*head) {
	node *p, *q, *r;
	if (head->next == NULL)
		return;
	p = head->next;
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		head->next = q;
		q->next = p;
		p = q;
		q = r;
	}
	p = head->next;	
}


int main() {
	node  d = { 'd', NULL }, c = { 'c', &d }, b = { 'b', &c }, a = { 'a', &b };
	//node *head = (node*)malloc(sizeof(node*));
	node* head = new node;
	cout << sizeof(node*)<<endl;
	cout << sizeof(node) << endl;
	head->next = &a;
	Reverse(head);
	node* temp = head->next;
	while (temp != NULL) {
		cout << temp->a << "  ";
		temp = temp->next;
	}
		
	//free(head);
	return 0;
}