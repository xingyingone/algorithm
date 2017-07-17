#include <iostream>
using namespace std;
struct node
{
	int data;
	node(int m=0) :data(m),next(NULL) {}
	struct node* next;
};
typedef struct node bnode;
void push(bnode** node, int m) {
	bnode* temp = new bnode(m);
	temp->next = *node;
	*node=temp;
}
bnode*SortedMerge(bnode* a, bnode* b) {
	bnode* temp = new bnode;
	bnode* tmp = temp;
	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			temp->next = a;
			a = a->next;
		}
		else {
			temp->next = b;
			b = b->next;
		}
		temp = temp->next;
	}
	while (a != NULL ) {
		temp->next = a;
		a = a->next;
		temp = temp->next;
	}
	while (b != NULL) {
		temp->next = b;
		b = b->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return tmp->next;
}
bnode*SortedMerge_1(bnode* a, bnode* b) {
	bnode* result = NULL;
	/*Base cases*/
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/*Pick either a or b, and recur */
	if (a->data <= b->data){
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}
void printList(bnode* res) {
	while (res != NULL) {
		cout << res->data << "  ";
		res = res->next;
	}
	cout << endl;
}
void main()
{
	bnode* res = NULL;
	bnode* a = NULL;
	bnode* b = NULL;

	/*Let us create two sorted linked lists to test the functions
	Created lists shall be a:5->10->15, b:2->3->20 */

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	res = SortedMerge(a, b);
	printList(res);
}
