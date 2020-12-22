#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
  int data; 
  struct Node* next; 
}; 

void push(struct Node** head, int temp) 
{ 
  struct Node* newnode = (Node*)malloc(sizeof(Node)); 
  newnode->data = temp; 
  newnode->next = (*head); 
  (*head) = newnode; 
} 

int GetNth(struct Node* head, int index) 
{ 
  struct Node* current = head; 
  int count = 0; 
  while (current != NULL) { 
    if (count == index) 
      return (current->data); 
    count++; 
    current = current->next; 
    } 
  assert(0); 
} 
  
int main() 
{ 
  struct Node* head = NULL; 
  push(&head, 30); 
  push(&head, 23); 
  push(&head, 22); 
  push(&head, 17); 
  push(&head, 10); 
  printf("Element at index 3 is %d", GetNth(head, 3)); 
  getchar(); 
}