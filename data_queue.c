#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a) < (b) ? (a) : (b);

// To execute C, please define "int main()"

size_t stack_direction_helper(); 
int stack_direction() {
 int value = 0;
 size_t addr1 = &value;
 size_t addr2 = stack_direction_helper();
 if (addr2 < addr1) {
   return -1;
 } else {
   return 1;
 }
}
size_t stack_direction_helper() {
 int value = 0;
 return &value;
}

typedef struct _queue {
  char *data;
  int front;
  int tail;
  int size;
} queue;
int queue_init(queue *q, int size) 
{
  if (!q || size <= 1) {
    return -1;
  }
  q->data = malloc(size);
  if (!q->data) {
    return -2;
  }
  q->front = 0;
  q->tail = 0;
  q->size = size;
  return 0;
}

int queue_enque(queue *q, char *data, int bytes)
{
  if (!q || !data || bytes <= 0) {
    return 0;
  }
  int free_slots = (q->size + q->tail - 1 - q->front) % q->size;
  int queued = min(free_slots, bytes);
  for (int i = 0; i < queued; i++) {
    q->data[q->front] = data[i];
    q->front = (q->front + 1) % q->size;
  }
  return queued;
}

int queue_deque(queue *q, char *data, int bytes)
{
  if (!q || !data || bytes <= 0) {
    return 0;
  }
  int elements = (q->size + q->front - q->tail) % q->size;
  int dequeued = min(elements, bytes);
  for (int i = 0; i < dequeued; i++) {
    data[i] = q->data[q->tail];
    q->tail = (q->tail + 1) % q->size;
  }
  return dequeued;
}

int main() {
  for (int i = 0; i < 5; i++) {
    printf("Hello, World\n");
  }
  queue q;
  int ret = queue_init(&q, 100);
  printf("ret:%d\n", ret);
  char data1[30] = "abcdefg";
  char data2[30] = "aaaaaaaaa";
  ret = queue_enque(&q, data1, 90); 
  printf("ret0:%d\n", ret);
  ret = queue_enque(&q, data1, 90); 
  printf("ret1:%d\n", ret);
  ret = queue_deque(&q, data2, 3); 
  printf("ret2:%d %s\n", ret, data2);
  ret = queue_deque(&q, data2, 3); 
  printf("ret3:%d %s\n", ret, data2);
  
  ret = stack_direction();
  printf("ret:%d\n", ret);
  
  return 0;
}

