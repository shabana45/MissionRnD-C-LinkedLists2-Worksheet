/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * createNode1(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
struct node*  add(struct node *head, int num){
	struct node *temp = head;
	if (head == NULL){
		(head) = createNode1(num);
		(head)->next = NULL;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode1(num);
		temp->next->next = NULL;
	}
	return head;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
	return NULL;
	int count = 0; 
	struct node* temp = head;  
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count<K)
		return head;
	else
	{
			struct node* temp1=head->next;
			temp = head;
			int i = 0;
			while (temp != NULL&& temp1 != NULL) {
	     		++i;
				if (i == K){
					struct node* new_node = (struct node*)malloc(sizeof(struct node));
					new_node->num = K;
					new_node->next = temp->next;
					temp->next = new_node;
					i = 0;
					temp = temp->next;
				}
				temp = temp->next;
				if (temp != NULL) 
					temp1 = temp->next;
			}
				if (K == 1){
					struct node* new_node = (struct node*)malloc(sizeof(struct node));
					new_node->num = K;
					new_node->next = NULL;
					temp->next = new_node;
				}
				return head;
			}
	   }

