#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

typedef struct Node {
	char reminder[MAX_STR_LEN]; /* data stored in the node */
	struct Node *next; /* Pointer to the next node */
} Node;

// Function prototypes 
void addNode(struct Node **head, const char *value);
void deleteNode();
void freeAll();
void printList();
#endif
