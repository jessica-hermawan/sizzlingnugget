#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2. Given a linked list, determine whether it has a cycle

struct Node {
  int score;
  Node *next;
};

void push(Node **head, int score){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->score = score;
  newNode->next = (*head);
  (*head) = newNode;
}

int cycle(struct Node* list){
  struct Node *cs = list, *cf = list;

  while(cs && cf && cf->next){
    cs = cs->next;
    cf = cf->next->next;
    if(cs == cf) return 1;
  }
  return 0;
}

int main(){
  struct Node* head = NULL;

  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);

  head->next->next->next->next = head;

  if(cycle(head)){
    printf("It has cycle!\n");
  } else {
    printf("No cycle found.\n");
  }
  return 0;
}