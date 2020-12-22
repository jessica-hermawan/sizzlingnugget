#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  int data;
  Node *next; 
}*head;

Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void pushHead(int data){
  Node *temp = createNode(data);
  if(!head){
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void printLinkedList(){
  Node *curr = head;
  while(curr){
    printf("%d ",curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  pushHead(132);
  pushHead(339);
  pushHead(528);
  pushHead(619);
  pushHead(783);
  printLinkedList();
return 0;
}