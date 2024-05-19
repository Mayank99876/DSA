#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAXSTK 100
class Stack
{

    int data[MAXSTK];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int item)
    {
        if (top == MAXSTK - 1)
        {
            cout << "OVERFLOW..." << endl;
            return;
        }
        top++;
        data[top] = item;
    }

    int pop()
    {
        int item;
        if (top == -1)
        {
            cout << "UNDERFLOW..." << endl;
            return -1;
        }
        item = data[top];
        top--;
        return item;
    }

    int peep()
    {
        int item;
        if (top == -1)
        {
            cout << "UNDERFLOW..." << endl;
            return -1;
        }
        item = data[top];
        return item;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << endl;
            ;
        }
    }

    bool isEmpty()
    {
        return top == -1 ? 1 : 0;
    }
};

int main()
{
    Stack s1; // Stack created
    int ch, item;
    do
    {
        cout << "1. push 2. pop 3. peep 4. display 5. exit\n Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter item to push: ";
            cin >> item;
            s1.push(item);
            break;
        case 2:
            if (!s1.isEmpty())
            {
                item = s1.pop();
                cout << "Popped item is " << item << endl;
            }
            else
                cout << "Stack is empty...";
            break;

        case 3:
            if (!s1.isEmpty())
            {
                item = s1.peep();
                cout << "Peeped item is " << item << endl;
            }
            else
                cout << "List is empty...";
            break;

        case 4:
            s1.display();
            break;
        case 5:
            break;
        default:
            cout << "Invalid input..." << endl;
            break;
        }
    } while (ch != 5);
    return 0;
}
