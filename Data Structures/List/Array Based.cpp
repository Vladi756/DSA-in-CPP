#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class MyArrayList {

private:
    int *array;
    int capacity;
    int currentSize;

public:
    MyArrayList(int capacity){
        this->array = new int[capacity];
        this->capacity = capacity;
        this->currentSize = 0;
    }

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->currentSize;
    }

    void setSize(int s) {
        if((s >= 0)&&(s<=this->capacity)){
            this->currentSize = s;
        }else {
            throw "Bad size value!";
        }
    }
 // Grey Bar
    void insertItem(int data, int index){   // Instance method within class - no need for array parameter.
        if((index < 0)||(index > this->currentSize)){
            throw "Bad index value!";
        }
        if(this->currentSize == this->capacity){
            throw "Attempt to exceed capacity!";
        }

        int i = this->currentSize;
        while(i > index){
            this->array[i] = this->array[i-1];
            i = i -1;
        }
        this->array[index] = data;
        this->currentSize =  this->currentSize + 1;
    }

    void display(){
        int i = 0;
        while(i < this->currentSize){
            cout << "Element " << i << ": " << this->array[i] << endl;
            i = i + 1;
        }
    }

    int removeItem(int index){
        if((index < 0)|| (index > this->currentSize)) {
            throw "Bad index value!";
        }
        int removed = this->array[index];
        int i = index;
        while(i < this->currentSize - 1){
            this->array[i] = this->array[i+1];
            i = i + 1;
        }
        this->currentSize = this->currentSize - 1;
        return removed;
    }

    int getItem(int index) {
        if((index < 0)||(index > this->currentSize)){
            throw "Bad index value!";
        }
        return this->array[index];
    }

    int setItem(int index, int data){
        if((index <0) || (index > this->currentSize)) {
            throw "Bad index value!";
        }
        int old = this->array[index];
        this->array[index] = this->array[data];
        return old;
    }
};

int main(){ // Function in main file used to seed a list and test the funcions above.
try {
    srand(time(NULL));

    MyArrayList list (100000);

    int i = 0;
    while (i < 10) {
        list.insertItem(rand() % 100, list.getSize());
        i = i + 1;
    }
    list.display();

    cout << "Item at index 2 = " << list.getItem(2) << endl;
    //cout << "Item at index 20000 = " << list.getItem(20000) << endl; // "Bad index value !"

    cout << "Inserting 999 at position 5" << endl;
    list.insertItem(999, 5);
    list.display();

    cout << "Deleting from position 2" << endl;
    list.removeItem(2);
    list.display();
}   catch(const char* msg) {
        cerr << msg << endl;
    }
}


