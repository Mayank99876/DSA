#include <stdio.h>
#define MAXQ 5
typedef struct queue
{
    int data[MAXQ];
    int front, rear;
} Queue;

void enque(Queue *, int);
int deque(Queue *);
void display(Queue);
int main()
{
    Queue q1;
    q1.front = q1.rear = -1;
    enque(&q1, 10);
    enque(&q1, 20);
    enque(&q1, 30);
    enque(&q1, 40);
    enque(&q1, 50);
    display(q1);
    printf("Item removed is: %d\n", deque(&q1));
    printf("Item removed is: %d\n", deque(&q1));
    printf("Item removed is: %d\n", deque(&q1));
    printf("Item removed is: %d\n", deque(&q1));
    printf("Item removed is: %d\n", deque(&q1));
    return 0;
}

void enque(Queue *p, int item)
{
    if (p->rear == MAXQ - 1)
    {
        printf("OVERFLOW...");
        return;
    }
    else if (p->front == -1)
    { // adding first element in queue
        p->front = 0;
    }
    // adding other elements in queue
    p->rear++;
    p->data[p->rear] = item;
}

int deque(Queue *p)
{
    int item;
    if (p->front == -1 || p->front > p->rear)
    {
        printf("UNDERFLOW...");
        return -1;
    }
    item = p->data[p->front];
    if (p->front == p->rear)
    { // deleting last element of queue
        p->front = p->rear = -1;
    }
    else
        p->front++;
    return item;
}

void display(Queue q1)
{
    int i = 0;
    printf("\nQueue is ");
    if (q1.front == -1)
    {
        printf("Empty");
        return;
    }
    for (i = q1.front; i <= q1.rear; i++)
    {
        printf("%d\t", q1.data[i]);
    }
    printf("\n");
}
