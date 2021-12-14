#include <stdio.h>
#define SIZE 5
int items[SIZE], front = -1, rear = -1;

void enQueue(int value){
  if(rear == SIZE - 1)
    printf("\nHàng đợi đã đầy!!!");
  else{
    if(front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nThêm -> %d\n", value);
  }
}

void deQueue(){
  if(front == -1)
    printf("\nHàng đợi rỗng!!!");
  else{
    printf("\nXóa : %d", items[front]);
    front++;
    if(front > rear)
      front = rear = -1;
  }
}

void display(){
  if(rear == -1)
    printf("\nHàng đợi rỗng!!!");
  else {
    int i;
    printf("\nCác phần tử trong hàng đợi là:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

int main() {
  printf("\nThêm các phần tử vào queue: ");
  for(int i = 0; i < 5; i++){
    enQueue(i);
  }
  //Không thể thêm do size của queue được khai báo là 5
  enQueue(6);
  
  display();

  deQueue();
  printf("\nHàng đợi sau khi xóa một phần tử: ");
  display();

  return 0;
}
