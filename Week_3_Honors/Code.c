#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct DoublyLinkedList {
  struct Node* head;
  struct Node* tail;
};

// Function prototypes
void insert_at_beginning(struct DoublyLinkedList* list, int data);
void insert_at_end(struct DoublyLinkedList* list, int data);
void print_list(struct DoublyLinkedList* list);
void remove_duplicates_sorted(struct DoublyLinkedList* list);
void remove_duplicates_first_element(struct DoublyLinkedList* list);

int main() {
  struct DoublyLinkedList list = {NULL, NULL};

  // Generate 200 random integers in the range [0, 49]
  for (int i = 0; i < 200; i++) {
    int data = rand() % 50;
    insert_at_end(&list, data);
  }

  printf("Original list:\n");
  print_list(&list);
  remove_duplicates_first_element(&list);
  printf("List after removing duplicates:\n");
  print_list(&list);

  return 0;
}

void insert_at_beginning(struct DoublyLinkedList* list, int data) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = list->head;
  new_node->prev = NULL;

  if (list->head == NULL) {
    list->tail = new_node;
  } else {
    list->head->prev = new_node;
  }
  list->head = new_node;
}
void insert_at_end(struct DoublyLinkedList* list, int data) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = list->tail;

  if (list->tail == NULL) {
    list->head = new_node;
  } else {
    list->tail->next = new_node;
  }
  list->tail = new_node;
}
void print_list(struct DoublyLinkedList* list) {
  struct Node* current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
void remove_duplicates_sorted(struct DoublyLinkedList* list) {
  // Sort the list using an external sorting function

  struct Node* current = list->head;
  struct Node* prev = NULL;

  while (current != NULL) {
    if (prev != NULL && current->data == prev->data) {
      // Remove duplicate node
      struct Node* temp = current;
      current = current->next;
      if (current != NULL) {
        current->prev = prev;
      }
      prev->next = current;
      free(temp);
    } else {
      prev = current;
      current = current->next;
    }
  }
}
void remove_duplicates_first_element(struct DoublyLinkedList* list) {
  struct Node* current = list->head;

  while (current != NULL) {
    struct Node* next_node = current->next;
    struct Node* prev = current;

    while (next_node != NULL) {
      if (next_node->data == current->data) {
        // Remove duplicate node
        prev->next = next_node->next;
        if (next_node->next != NULL) {
          next_node->next->prev = prev;
        }
        free(next_node);
        next_node = prev->next;
      } else {
        prev = next_node;
        next_node = next_node->next;
      }
    }
    current = current->next;
  }
}

