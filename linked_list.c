#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "reminder.h"
#include "linked_list.h"


void addNode(Node** head, const char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for a new node
    if (new_node == NULL) {
        printf("Memory allocation failed!\n"); //Memory allocatio failure
        return;
    }

    // Copy the reminder string into the new node
    strncpy(new_node->reminder, value, MAX_STR_LEN);
    new_node->reminder[MAX_STR_LEN - 1] = '\0';  // Null-termination
    new_node->next = NULL;  // New node points to end of the list, which is null
    
    // If the linked list is empty, initialize it with the new node
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Otherwise, traverse to the end of the list and append the new node
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void deleteNode(struct Node **head, struct Node **node) {
	if (*head == NULL) {
		printf("The list is empty. \n");
		return;
	}
	
	if (*head == *node) {
		*head = (*head)->next;
		free(*node);
		*node = NULL;
		return;
	}
	struct Node *curr = *head;
	struct Node *prev = NULL;
	
	while (curr != NULL && curr != *node) {
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("Node not found.\n");
		return;
	}
	prev->next = curr->next;
	
}
void freeAllNodes(struct Node **head) {
	struct Node *curr = *head;
	while (curr != NULL) {
		struct Node  *nextNode = curr->next;
		free(curr);
		curr = nextNode;
	}
}	
