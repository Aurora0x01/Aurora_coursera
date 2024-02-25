#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the linked list
struct node {
   int data;
   struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct node **head, int data) {
   struct node *newNode = createNode(data);
   if (*head == NULL) {
       *head = newNode;
       return;
   }
   struct node *current = *head;
   while (current->next != NULL) {
       current = current->next;
   }
   current->next = newNode;
}

// Function to swap two nodes
void swapNodes(struct node **head, struct node *a, struct node *b) {
   if (*head == a) {
       *head = b;
   }
   if (a->next == b) {
       a->next = b->next;
   } else {
       struct node *temp = b->next;
       b->next = a->next;
       a->next = temp;
   }
}

// Function to sort the list using bubble sort
void bubbleSort(struct node **head) {
   int swapped;
   struct node *current, *next;

   do {
       swapped = 0;
       current = *head;
       while (current->next != NULL) {
           next = current->next;
           if (current->data > next->data) {
               swapNodes(head, current, next);
               swapped = 1;
           }
           current = next;
       }
   } while (swapped);
}

// Function to print the list in rows of 5
void printList(struct node *head) {
   int count = 0;
   while (head != NULL) {
       printf("%d ", head->data);
       count++;
       if (count % 5 == 0) {
           printf("\n");
       }
       head = head->next;
   }
}

int main() {
   srand(time(NULL));  // Seed the random number generator

   struct node *head = NULL;

   // Generate 100 random integers and insert them into the list
   for (int i = 0; i < 100; i++) {
       int data = rand() % 1000;  // Generate random integers up to 999
       insertNode(&head, data);
   }

   printf("Unsorted list:\n");
   printList(head);

   bubbleSort(&head);

   printf("\nSorted list:\n");
   printList(head);

   return 0;
}
