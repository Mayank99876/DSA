#include <iostream>
#include <string>
#define MAXSTK 100

using namespace std;

struct Stack
{
    int data[MAXSTK];
    int top;
};

void push(Stack *, int); // call by reference
int pop(Stack *);        // call by reference
int peep(Stack);         // call by value
void display(Stack);     // call by value
int isEmpty(Stack);
int isValid(string);

int main()
{
    int ans;
    string eq;
    cout << "Enter equation: ";
    getline(cin, eq);
    ans = isValid(eq);
    if (ans == 1)
        cout << "Expression is valid.";
    else
        cout << "Expression is not valid.";
    return 0;
}

void push(Stack *p, int item)
{
    if (p->top == MAXSTK - 1)
    {
        cout << "OVERFLOW..." << endl;
        return;
    }
    p->top++;
    p->data[p->top] = item;
}

int pop(Stack *p)
{
    int item;
    if (p->top == -1)
    {
        cout << "UNDERFLOW..." << endl;
        return -1;
    }
    item = p->data[p->top];
    p->top--;
    return item;
}

int peep(Stack s1)
{
    int item;
    if (s1.top == -1)
    {
        cout << "UNDERFLOW..." << endl;
        return -1;
    }
    item = s1.data[s1.top];
    return item;
}

void display(Stack s1)
{
    for (int i = s1.top; i >= 0; i--)
    {
        cout << s1.data[i] << endl;
    }
}

int isEmpty(Stack s1)
{
    return s1.top == -1 ? 1 : 0;
}

int isValid(string eq)
{
    Stack s1;
    int i = 0;
    s1.top = -1;
    while (eq[i] != '\0')
    {
        if (eq[i] == '(')
        {
            push(&s1, eq[i]);
        }
        else if (eq[i] == ')')
        {
            if (isEmpty(s1))
                return -1;
            else
                pop(&s1);
        }
        i++;
    }
    if (isEmpty(s1))
        return 1;
    else
        return -1;
}
