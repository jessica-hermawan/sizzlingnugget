#include <stdio.h>
#include <stdlib.h>
 
//4. Given a sorted linked list, remove all the duplicates.

struct Node { 
  int data; 
  Node *next; 
}; 
 
void removeDuplicates(Node *head) { 
  Node *current = head; 
  
  Node* next_next;  
    
  if (current == NULL) return;  
  
  while (current->next != NULL) {
    if (current->data == current->next->data) { 
    // The sequence of steps is important              
    next_next = current->next->next; 
    free(current->next); 
    current->next = next_next;   
    } else { 
      current = current->next;  
      } 
    } 
} 

void pushHead(struct Node **head, int new_data) { 
  Node *newNode = (Node*) malloc(sizeof(Node)); 
  newNode->data  = new_data; 
  newNode->next = (*head);      
  (*head) = newNode; 
} 
  
void printLinkedList(Node *node) 
{ 
  while (node!=NULL) { 
    printf("%d ", node->data); 
    node = node->next; 
  } 
}  
  
/* Driver program to test above functions*/
int main() { 
  Node *head = NULL; 
  pushHead(&head, 7); 
  pushHead(&head, 7); 
  pushHead(&head, 3);   
  pushHead(&head, 3); 
  pushHead(&head, 3); 
  pushHead(&head, 3);
  pushHead(&head, 2); 
  pushHead(&head, 2); 
  pushHead(&head, 2);

  
  printf("\n Original linked list : "); 
  printLinkedList(head);  
 
  removeDuplicates(head);  
  
  printf("\n Duplicates removed : ");          
  printLinkedList(head);             
    
  return 0; 
} 