#include <iostream>
using namespace std;

class Queue
{
    int *arr; 
    int front, rear;
    int capacity;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() 
    {
        delete[] arr; 
    }

    void enqueue(int x)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if (front == -1)
                front = 0;
            arr[++rear] = x;
            cout << x << " enqueued into queue\n";
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            cout << arr[front++] << " dequeued from queue\n";
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    Queue q(size);

    cout << "Enter " << size << " elements to enqueue:\n";
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        q.enqueue(val);
    }

    cout << "\nCurrent queue:\n";
    q.display();

    cout << "\nPerforming dequeue:\n";
    q.dequeue();

    cout << "\nAfter dequeue:\n";
    q.display();

    return 0;
}
