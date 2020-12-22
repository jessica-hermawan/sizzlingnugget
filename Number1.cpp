#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.

struct Node {
  int number;
  Node *next;
}*head, *tail;

Node *createNode(int key){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->number = key;
  newNode->next = NULL;
  return newNode;
}

void printLinkedList(Node *curr){
  while(curr!=NULL){
    printf("%d ", curr->number);
    curr = curr->next;
  }
}

Node *sortedMerge(Node *L1, Node *L2){
  if(!L1){
    return L2;
  }
  if(!L2){
    return L1;
  }

  if(L1->number < L2->number){
    L1->next = sortedMerge(L1->next, L2);
    return L1;
  } else{
    L2->next = sortedMerge(L1, L2->next);
    return L2;
  }
}

int main(){
  //sorted List 1
  printf("List 1: 2 -> 3 -> 7\n");
  Node *L1 = createNode(2);
  L1->next = createNode(3);
  L1->next->next = createNode(7);

  //sorted List 2;
  printf("List 2: 0 -> 1 -> 5\n");
  Node *L2 = createNode(0);
  L2->next = createNode(1);
  L2->next->next = createNode(5);

  Node *mergeList = sortedMerge(L1, L2);

  printLinkedList(mergeList);
  
  return 0;
}