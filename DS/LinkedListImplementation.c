/**
 * Title     : Linked List Implementation
 * Author    : Tridib Samanta
 **/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void InsertAtFirst(int data) {
	struct Node* tempNode = (struct Node*) malloc(sizeof(struct Node));
	tempNode->data = data;
	tempNode->next = head;
	head = tempNode;
}

void InsertAtPosition(int data, int pos) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    int i;
    for(i = 0; i < pos - 2; ++i) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position !\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void InsertAtTail(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void DeleteAtFirst() {
    if (head == NULL) {
        printf("Deletion cannot be performed as list is empty !\n");
        return;
    }
    struct Node* temp = head;
    head = temp->next;
    free(temp);
}

void DeleteAtPosition(int pos) {
    if (head == NULL) {
        printf("Deletion cannot be performed as list is empty !\n");
        return;
    }
    struct Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    int i;
    for (i = 0; i < pos - 2; ++i) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position !\n");
            return;
        }
    }
    struct Node* target = temp->next;
    temp->next = target->next;
    free(target);
}

void DeleteAtTail() {
    if (head == NULL) {
        printf("Deletion cannot be performed as list is empty !\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {
        head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void DisplayList() {
	if (head == NULL)
		printf("List is empty !\n");
	else {
		struct Node* temp = head;
		printf("List is - ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {

	head = NULL;

	DisplayList();
	InsertAtTail(2); DisplayList();
	InsertAtFirst(1); DisplayList();
	InsertAtPosition(1, 1); DisplayList();
	InsertAtPosition(3, 4); DisplayList();
	InsertAtFirst(0); DisplayList();
	InsertAtTail(5); DisplayList();

	DeleteAtTail(); DisplayList();
	DeleteAtFirst(); DisplayList();
    DeleteAtPosition(4); DisplayList();
    DeleteAtFirst(); DisplayList();
    DeleteAtPosition(1); DisplayList();
    DeleteAtTail(); DisplayList();

	return 0;
}

/*
 *** TRAVERSAL ***
 * Time Complexity  : O(n), for traversing a list of n elements.
 * Space Complexity : O(1), for creating a temporary variable.
 *
 *** INSERTION ***
 * Time Complexity  : O(n), since, in the worst case, we may need to insert a node at the end of the list.
 * Space Complexity : O(1), for creating a temporary variable.
 *
 *** DELETION ***
 * Time Complexity  : O(n), since, in the worst case, we may need to delete a node at the end of the list.
 * Space Complexity : O(1), for creating a temporary variable.
*/

/* OUTPUT :

List is empty !
List is - 2
List is - 1 2
List is - 1 1 2
List is - 1 1 2 3
List is - 0 1 1 2 3
List is - 0 1 1 2 3 5
List is - 0 1 1 2 3
List is - 1 1 2 3
List is - 1 1 2
List is - 1 2
List is - 2
List is empty !

*/

