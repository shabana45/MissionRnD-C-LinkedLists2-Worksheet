/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
		return -1;
	if (head->next == NULL)//length=1
		return head->num;
	struct node* temp = head;
	struct node* last = head;
	while (last->next != NULL && last->next->next != NULL){
		last = last->next->next;
		temp = temp->next;
	}
	if (last->next == NULL) //odd length
		return temp->num;
	else   //Even length
		return (temp->num + temp->next->num) / 2;
}
