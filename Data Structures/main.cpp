#include <iostream>

#define MAXSIZE 5

class Queue{

private:
    int head ;  // Initial state - Queue is empty
    int tail;
    int arr[MAXSIZE];   // MAXSIZE defined so as not to hard code the program

public:
    // Constructor
    Queue(){
        tail = -1;
        head = -1;
        for(int i = 0; i < MAXSIZE; i++){
            arr[i] = 0;
        }
    }

    // Checks is Queue is empty
    bool isEmpty(){
        if(head == -1 && tail == -1){
            return true;
        } else {
            return false;
        }
    }
    // Checks if Queue is full
    bool isFull() {
        if(tail == MAXSIZE - 1){
            return true;
        } else {
            return false;
        }
    }
    // Adds an element to the tail of the Queue
    void enQueue(int data){
        if(isFull()){
            std::cout << "Cannot enQueue - queue is full!" << std::endl;
            return;
        }else if(isEmpty()){
            tail = head = 0;
            arr[tail] = data;
        } else {
            tail++;
            arr[tail] = data;
        }
    }
    // Removes element from hear of Queue
    int deQueue(){
        int x;
        if(isEmpty()){
            std::cout << "Nothing to remove, queue is empty!" << std::endl;
            return 0;
        } else if(head == 0 && tail == 0){
            x = arr[head];
            arr[head] = 0;
            head = -1;
            tail = -1;
            return x;
        } else {
            x = arr[head];
            arr[head] = 0;
            head++;
            return x;
        }
    }
    // Returns number of elements in Queue
    int count(){
        if(isEmpty())
            return 0;
        else
             return (tail - head) + 1;
    }
    // Displays Queue
    void display(){
        std::cout << "All values in the queue are:" << std::endl;
        for (int i = 0; i < MAXSIZE; i++){
            std::cout << arr[i] << std::endl;
        }
    }
};



int main()
{
    Queue q1;
    int option, value;
    do {
        std::cout << "\nWhich operation would you like to perform? Select the option number." << std::endl;
        std::cout << "\n1. Enqueue()" << std::endl;
        std::cout << "2. Dequeue()" << std::endl;
        std::cout << "3. isEmpty()" << std::endl;
        std::cout << "4. isFull()" << std::endl;
        std::cout << "5. count()" << std::endl;
        std::cout << "6. display()" << std::endl;
        std::cout << "7. Clear Screen" << std::endl;
        std::cout << "\n0. Exit" << std::endl;

        std::cin >> option;

        switch(option){
        case 0:
            break;
        case 1:
            std::cout << "\nEnter an item to Enqueue in the Queue" << std::endl;
            std::cin >> value;
            q1.enQueue(value);
            break;
        case 2:
            std::cout << "\nDequeueing value: " << q1.deQueue() << std::endl;
            break;
        case 3:
            if(q1.isEmpty()){
                std::cout << "Queue is empty!" << std::endl;
            } else {
                std::cout << "Queue is not empty!" << std::endl;
            }
            break;
        case 4:
            if(q1.isFull()){
                std::cout << "Queue is full!" << std::endl;
            } else {
                std::cout << "Queue is not full!" << std::endl;
            }
            break;
        case 5:
            std::cout << "\nCount of items in queue:" << q1.count() << std::endl;
            break;
        case 6:
            q1.display();
            break;
        case 7:
            system("cls"); // clears the command prompt
            break;
        default:
            std::cout << "Enter a valid number!" << std::endl;
            break;
        }

    } while(option!=0);

    return 0;
}
