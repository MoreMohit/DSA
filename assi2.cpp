
#include <iostream>
using namespace std;
#define n 6

class Queue 
{
    int* arr;
    int front;
    int rear;

public:
    Queue() 
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue() 
    {
        if (isfull()) 
        {
            cout << "Queue full" << endl;
            return;
        }
        else 
        {
            int x;
            cout << "Enter number to enqueue: ";
            cin >> x;

            // Check if the queue is full
            if ((rear + 1) % n == front) 
            {
                cout << "Queue is overflow" << endl;
                return;
            }
            // If the queue is empty, initialize front and rear to 0
            if (front == -1 && rear == -1) 
            {
                front = 0;
                rear = 0;
            }
           
            else 
            {
                rear = (rear + 1) % n; // Circular increment
            }

            arr[rear] = x;
            cout << "Inserted " << x << " front: " << front << " at rear: "
       << rear << endl;
        }
        display();
    }

    void dequeue() 
    {
        if (isempty()) 
        {
            cout << "Queue empty" << endl;
            return;
        }

        else 
        {
            int remove = arr[front];
            // Check if front and rear are equal 
                 // it means the queue has only one element
            if (front == rear) 
            {
                front = -1;
                rear = -1;
            }
            else 
            {
                front = (front + 1) % n; // Circular increment
            }

            cout << "Removed element " << remove << " Front: " << front 
   << " and Rear: " << rear << endl;
        }
        display();
    }

    bool isempty() 
    {
        return (front == -1 && rear == -1);
    }




    bool isfull() 
    {
        return ((rear + 1) % n == front);
    }

    void display() 
    {
        if (isempty()) 
        {
            cout << "Queue empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) 
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % n;
        }
        cout << endl;
    }
};

int main() 
{
    Queue u;
    int choice;

    while (true) 
{
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
    {
        case 1:
            u.enqueue();
            break;

       

       case 2:
            u.dequeue();
            break;

        case 3:
            u.display();

            break;
        case 4:
            exit(0);

        default:
            cout << "Invalid choice" << endl;
    }
}
    return 0;
}


