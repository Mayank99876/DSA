// error topological sorting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXQ 20
typedef struct Queue
{
    int data[MAXQ];
    int front, rear;
} Queue;

void addq(Queue *p, int item)
{
    if (p->rear == MAXQ - 1)
        return;
    if (p->front = -1)
        p->front = p->rear = 0;
    else
        p->rear++;
    p->data[p->rear] = item;
}

int delq(Queue *p)
{
    int item;
    if (p->front == -1)
        return -999;
    item = p->data[p->front];
    if (p->front == p->rear)
        p->front = p->rear = -1;
    else
        p->front++;
    return item;
}

int main()
{
    Queue q1;
    q1.front = q1.rear = -1;
    int a[10][10], indeg[10], flag[10];
    int i, j, k, n, count = 0;
    printf("enter no. of vertices: ");
    scanf("%d", &n);
    printf("enter adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // initialize
    for (i = 0; i < n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == 1)
                indeg[j]++;

    printf("The topological order is: ");
    do
    {
        // To check new nodes with 0 indegree
        for (k = 0; k < n; k++)
        {
            if (indeg[k] == 0 && flag[k] == 0)
            {
                addq(&q1, k);
                flag[k] = 1;
            }
        }
        k = delq(&q1);
        printf("%c", k + 'A');
        // This code will decrease indegree of each node effected by the deleted node
        for (i = 0; i < n; i++)
        {
            if (a[k][i] == 1)
            {
                indeg[i]--;
            }
        }
    } while (q1.front != -1);
    return 0;
}
