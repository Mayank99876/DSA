#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTK 100

typedef struct Stack {
    char data[MAXSTK];
    int top;
} Stack;

void push(Stack *, char); // call by reference
char pop(Stack *);        // call by reference
char peep(Stack);         // call by value
void intoPost(char[], char[]);
void intoPre(char[], char[]);
int precedence(char);
int isOperator(char);

int main() {
    char infix[50], postfix[50], prefix[50];
    printf("Enter infix expression: ");
    gets(infix);
    intoPost(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
    intoPre(infix, prefix);
    printf("Prefix expression is: %s\n", prefix);
    return 0;
}

void intoPost(char infix[], char postfix[]) {
    Stack s1;
    char ch;
    int i = 0; // for infix expression
    int j = 0; // for postfix expression
    s1.top = -1;
    // Left to Right Scan in case of Postfix
    while (infix[i] != '\0') {
        if (infix[i] == '(') { // left parenthesis
            push(&s1, infix[i]);
        } else if (infix[i] == ')') { // right parenthesis
            ch = pop(&s1);
            while (ch != '(') {
                postfix[j++] = ch;
                ch = pop(&s1);
            }
        } else if (isOperator(infix[i])) { // Operator
            ch = peep(s1);
            while (ch != '(' && precedence(ch) >= precedence(infix[i])) {
                postfix[j++] = pop(&s1);
                ch = peep(s1);
            }
            push(&s1, infix[i]);
        } else { // Operand
            postfix[j++] = infix[i];
        }
        i++;
    }
    // Pop remaining operators from the stack
    while (s1.top != -1) {
        postfix[j++] = pop(&s1);
    }
    postfix[j] = '\0';
}

void intoPre(char infix[], char prefix[]) {
    Stack s1;
    char ch;
    int i = strlen(infix) - 1; // for infix expression
    int j = 0;                  // for prefix expression
    s1.top = -1;
    // Right to Left Scan in case of Prefix
    while (i >= 0) {
        if (infix[i] == ')') { // right parenthesis
            push(&s1, infix[i]);
        } else if (infix[i] == '(') { // left parenthesis
            ch = pop(&s1);
            while (ch != ')') {
                prefix[j++] = ch;
                ch = pop(&s1);
            }
        } else if (isOperator(infix[i])) { // Operator
            ch = peep(s1);
            while (ch != ')' && precedence(ch) > precedence(infix[i])) {
                prefix[j++] = pop(&s1);
                ch = peep(s1);
            }
            push(&s1, infix[i]);
        } else { // Operand
            prefix[j++] = infix[i];
        }
        i--;
    }
    // Pop remaining operators from the stack
    while (s1.top != -1) {
        prefix[j++] = pop(&s1);
    }
    prefix[j] = '\0';
    // Reverse the prefix expression to get the correct order
    strrev(prefix);
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isOperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    else
        return 0;
}

void push(Stack *p, char item) {
    if (p->top == MAXSTK - 1) {
        printf("OVERFLOW...\n");
        return;
    }
    p->top++;
    p->data[p->top] = item;
}

char pop(Stack *p) {
    char item;
    if (p->top == -1) {
        printf("UNDERFLOW...\n");
        return '\0'; // Return a default value in case of underflow
    }
    item = p->data[p->top];
    p->top--;
    return item;
}

char peep(Stack s1) {
    char item;
    if (s1.top == -1) {
        printf("UNDERFLOW...\n");
        return '\0'; // Return a default value in case of underflow
    }
    item = s1.data[s1.top];
    return item;
}
