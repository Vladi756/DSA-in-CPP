#include <iostream>
#include <string>

#define MAXSIZE 5

using namespace std;

class Stack{
private:
    int top;
    int arr[MAXSIZE];

public:
    Stack(){
        top = -1;
        for(int i = 0; i < MAXSIZE; i++){
            arr[i] = 0;
        }
    }
    bool isEmpty(){
        if(top == -1)
            return true;    // Empty
        else
            return false;   // Not Empty
    }
    bool isFull(){
        if(top == (MAXSIZE - 1))    // Zero based index position
            return true;    // Full
        else
            return false;   // Not Full
    }
    void push(int value){
        if(isFull()){
            cout << "Stack Overflow!" << endl;
        }
        else {
            top++;
            arr[top] = value;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return 0;
        }
        else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
    int count(){
        return(top + 1); // Zero Based index position - always one less
    }
    int peek(int index){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
        } else {
            return arr[index];
        }
    }
    void change(int index, int value){
        arr[index] = value;
        cout << "Value changed at index: " << index << endl;
    }
    void display(){
        cout << "All values in the Stack are: " << endl;
        for(int i = MAXSIZE-1; i >= 0; i--){
            cout << arr[i] << endl;
        }
    }

};

int main()
{
     Stack s1;
     int option, position, value;

     do {
        cout << "What operation do you want to perform? Enter 0 to exit." << endl;
        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;

        cin >> option;
        switch(option){
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack." << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Popping top item:" << s1.pop() << endl;
            break;
        case 3:
            if(s1.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
         case 4:
            if(s1.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;
         case 5:
            cout << "Enter position of item you want to peek: " << endl;
            cin >> position;
            cout << "Value at position "<< position << "is: " << s1.peek(position) << endl;
            break;
         case 6:
            cout << "Number of items in stack: " << s1.count() << endl;
            break;
         case 7:
            cout << "Enter position of item you want to change: ";
            cin >> position;
            cout << endl;
            cout << "Enter value of item you want to change: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Displaying..." << endl;
            s1.display();
            cout << endl;
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter Valid Option Number: " << endl;
        }

     } while(option != 0);

    return 0;
}
