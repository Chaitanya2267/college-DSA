#include <iostream>
using namespace std;

class Stack
{
    int *arr; 
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed into stack\n";
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack s(size);

    cout << "Enter " << size << " elements to push:\n";
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }

    cout << "\nCurrent stack:\n";
    s.display();

    cout << "\nPerforming pop:\n";
    s.pop();

    cout << "\nAfter pop:\n";
    s.display();

    return 0;
}
