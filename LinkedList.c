#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
  if (prev_node == NULL) {
    printf("Nút trước đó không thể là Null");
    return;
  }
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL){
    *head_ref = new_node;
    return;
  }
  while(last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}

void deleteNode(struct Node** head_ref, int key){
  struct Node *temp = *head_ref, *prev;
  if(temp != NULL && temp->data == key){
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while(temp != NULL && temp->data != key){
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

int searchNode(struct Node** head_ref, int key){
  struct Node* current = *head_ref;
  while(current != NULL){
    if(current->data == key) return 1;
    current = current->next;
  }
  return 0;
}

void printList(struct Node* node){
  while(node != NULL){
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main(){
  struct Node* head = NULL;
  
  insertAtEnd(&head, 25); insertAtEnd(&head, 6); insertAtEnd(&head, 15);
  printf("Linked list: ");
  printList(head);
  
  insertAtBeginning(&head, 9);
  printf("\nLinked list sau khi thêm phần tử vào đầu danh sách: ");
  printList(head); deleteNode(&head, 9);
  
  insertAtEnd(&head, 9);
  printf("\nLinked list sau khi thêm phần tử vào cuối danh sách: ");
  printList(head); deleteNode(&head, 9);
  
  insertAfter(head->next, 9);
  printf("\nLinked list sau khi thêm phần tử vào giữa danh sách: ");
  printList(head); deleteNode(&head, 9);

  printf("\nLinkes list sau khi xóa một phần tử: ");
  deleteNode(&head, 6);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)){
    printf("\n%d tồn tại trong danh sách", item_to_find);
  }else{
    printf("\n%d không tôn tại trong danh sách", item_to_find);
  }
}
