#include <stdio.h>  
#include <stdlib.h>  
/*Link list node*/
struct node
{
	int data;
	struct node* next;
};

/*function prototype */
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);

/*sorts the linked list by changing next pointers(not data) */
void MergeSort(struct node** headRef)
{
	struct node* head = *headRef;
	struct node* a;
	struct node* b;

	/*base case-- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/*Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/*Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

struct node* SortedMerge(struct node* a, struct node* b)
{
	struct node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the references parameters.
If the length is odd, the extra node shold go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
	struct node* fast;
	struct node* slow;

	if (source == NULL || source->next == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

/*Function to print nodes in a given linked list*/
void printList(struct node* node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
}

/* Function to insert a node at the begining of the linked list*/
void push(struct node** head_ref, int new_data)
{
	/*allocate node*/
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	/*put in the data*/
	new_node->data = new_data;

	/*link the old list off the new node*/
	new_node->next = (*head_ref);

	/*move the head to point to the new node*/
	(*head_ref) = new_node;
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* res = NULL;
	struct node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
	Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	MergeSort(&a);

	printf("\n Sorted Linked List is: \n");
	printList(a);

	return 0;
}