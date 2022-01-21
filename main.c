#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Οριζω το μεγεθος του πινακα με τις τιμες του καθε κομματιου της λιστας
#define numOfNodes 5 // Οριζω το πληθος των κομματιων της λιστας
struct node {
	int value[SIZE];
	struct node *next;
	struct node *prev;
};
typedef struct node nodet;

nodet *createnode(int a, nodet *temp){
	nodet *result = malloc (sizeof(nodet));
	result->prev = temp;
	temp->next = result;
	for (int i = 0; i < SIZE; i++){
		result->value[i] = (i+1) * a;
	}
	result->next = NULL;
	return result;
}

void printvalues(nodet *head) {
	nodet *temp = head;
	while (temp != NULL){
		if (temp->value[0] != -1){
			for (int i = 0; i < SIZE; i++){
				printf("%d ", temp->value[i]);
			}
			printf("\n");
		}
		temp = temp->prev;
	}
	printf("\n");
}

void getnexts(nodet *head){
	nodet *temp = head;
	nodet *temp2 = head;
	while (temp != NULL){
		temp = temp->prev;
		if (temp == NULL){
			break;
		}
		temp->next = temp2;
		temp2 = temp;
	}
}

void addattheend (nodet *head, int value){
	nodet *temp = head;
	nodet *temp2;
	temp2 = createnode(value, temp);
	temp->next = temp2;
	head = temp2;
	
}
void printvaluesnormally (nodet *tail){
	nodet *temp = tail;
	while (temp != NULL){
		if (temp->value[0] != -1){
			for (int i = 0; i < SIZE; i++){
				printf("%d ", temp->value[i]);
			}
			printf("\n");
		}
		temp = temp->next;
	}
	printf("\n");
}
int main(int argc, char *argv[]) {
	nodet *head = NULL;
	nodet *temp;
	nodet *tail = temp;
	temp->prev = NULL;
	temp->value[0] = -1;
	
	for (int i = 1; i <= numOfNodes; i++){
		temp = createnode((i*5), temp);
		head = temp;
	}
	getnexts (head);
	printvaluesnormally(tail);
	
	return 0;
}