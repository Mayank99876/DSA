// Errors:-----------
// display second queue
//  delfirstq and secondq
#include <stdio.h>
#define MAXQ 10
typedef struct queue
{
    int data[MAXQ];
    int front1, rear1;
    int front2, rear2;
} Queue;

void addfirstq(Queue *, int);
int delfirstq(Queue *);
void displayfirstq(Queue);
void addsecondq(Queue *, int);
int delsecondq(Queue *);
void displaysecondq(Queue);
int main()
{
    Queue q1;
    int ch, item;
    q1.front1 = q1.rear1 = -1;
    q1.front2 = q1.rear2 = MAXQ;
    do
    {
        printf("\t\t\tMAIN MENU\n");
        printf("********************\n");
        printf("1. addfirstq\n");
        printf("2. delfirstq\n");
        printf("3. displayfirstq\n");
        printf("4. addsecondq\n");
        printf("5. delsecondq\n");
        printf("6. displaysecondq\n");
        printf("7. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to add: ");
            scanf("%d", &item);
            addfirstq(&q1, item);
            break;
        case 2:
            item = delfirstq(&q1);
            if (item != 0)
                printf("Deleted item is: %d", item);
            break;
        case 3:
            displayfirstq(q1);
            break;
        case 4:
            printf("Enter item to add: ");
            scanf("%d", &item);
            addsecondq(&q1, item);
            break;
        case 5:
            item = delsecondq(&q1);
            if (item != 0)
                printf("Deleted item is: %d", item);
            break;
        case 6:
            displaysecondq(q1);
            break;
        case 7:
            break;
        default:
            printf("Invalid Input. Try again!");
        }
    } while (ch != 7);
    return 0;
}

void addfirstq(Queue *p, int item)
{
    if (p->rear1 + 1 == p->rear2)
    {
        printf("OVERFLOW...");
        return;
    }
    else if (p->front1 == -1)
    { // adding first element in queue
        p->front1 = 0;
    }
    // adding other elements in queue
    p->rear1++;
    p->data[p->rear1] = item;
}

int delfirstq(Queue *p)
{
    int item;
    if (p->front1 == -1 || p->front1 > p->rear1)
    {
        printf("UNDERFLOW...");
        return -1;
    }
    item = p->data[p->front1];
    if (p->front1 == p->rear1)
    { // deleting last element of queue
        p->front1 = p->rear1 = -1;
    }
    else
        p->front1++;
    return item;
}

void displayfirstq(Queue q1)
{
    int i = 0;
    printf("\nQueue is ");
    if (q1.front1 == -1)
    {
        printf("Empty");
        return;
    }
    for (i = q1.front1; i <= q1.rear1; i++)
    {
        printf("%d\t", q1.data[i]);
    }
    printf("\n");
}

void addsecondq(Queue *p, int item)
{
    if (p->rear1 + 1 == p->rear2)
    {
        printf("OVERFLOW...");
        return;
    }
    else if (p->front2 == MAXQ)
    { // adding first element in queue
        p->front2 = MAXQ - 1;
    }
    // adding other elements in queue
    p->rear2--;
    p->data[p->rear2] = item;
}

int delsecondq(Queue *p)
{
    int item;
    if (p->front2 == p->rear2 + 1 || p->front2 < p->rear2)
    {
        printf("UNDERFLOW...");
        return -1;
    }
    item = p->data[p->front2];
    if (p->front2 == p->rear2)
    { // deleting last element of queue
        p->front1 = p->rear1 = MAXQ;
    }
    else
        p->front2--;
    return item;
}

void displaysecondq(Queue q1)
{
    int i;
    printf("\nQueue is ");
    if (q1.front2 == MAXQ)
    {
        printf("Empty");
        return;
    }
    for (i = q1.front2; i <= q1.rear2; i--)
    {
        printf("%d\t", q1.data[i]);
    }
    printf("\n");
}
