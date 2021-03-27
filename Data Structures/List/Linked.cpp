#include <iostream>

using namespace std;

class Node {
public:                     // Public, so can be modified outside of Node class.
    int data;
    Node *next = nullptr;
    Node *previous = nullptr;
    Node(int data){
        this->data = data;
    }
};

class MyLinkedList {
private:                      // Private, so only instance methods can modify them.
    Node *head = nullptr;
    Node *tail = nullptr;
    int currentSize = 0;

public:
    // Appends a node to the end of the list.
    void appendItem(int data){
        Node *newNode = new Node(data);
        if(this->tail == nullptr){                  // If list is empty
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->previous = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->currentSize = this->currentSize + 1;
    };
    // Prepend item adds node to the beginning of the list
    void prependItem(int data){
        Node *newNode = new Node(data);
        if(this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }else {
            newNode->next = this->head;
            this->head->previous = newNode;
            this->head = newNode;
        }
        this->currentSize = currentSize + 1;
    }
    // Displays
    void display(){
        Node *node = this->head;
        cout << "Length = " << this->currentSize << endl;
        while(node!=nullptr){                       // nullptr would be tail of list (end)
            cout << node->data << endl;
            node = node->next;
        }
    }
    // Retruns node at given index if it exists, else, throws an exception.
    Node *getNode(int index){
        Node *node = this->head;
        if((node == nullptr)||(index < 0)) {        // Checks if index is invalid.
            throw "Bad Index Value!";
        }
        if(index == this->currentSize){             // If index tail, returns it immdeiately.
            return this->tail;
        }
        int i = 0;
        while(i < index){
            node = node->next;
            if(node == nullptr){
                throw "Bad Index Value!";           // Index exceeds length of list.
            }
            i = i + 1;
        }
        return node;                                // "node" is head of list remember.
    }
    // Gets data from node - "item"
    int getItem(int index){
        return this->getNode(index)->data;          // Propafaites exception from getNode in case bad index value.
    }
    // Insert item anywhere in list
    void insertItem(int data, int index){
        if((index < 0)||(index > this->currentSize)){
            throw "Bad Index Value!";
        }
        if(index == 0) {                            // Making use of previous functions to help with this one.
            this->prependItem(data);
        } else if(index == this->currentSize) {
            this->appendItem(data);
        } else {
            Node *newNode = new Node(data);         // The actual node we're inserting.
            Node *preceding = this->getNode(index-1);   // Can't be null
            Node *existing = preceding->next;           // Can be null iff index = currentSize

            preceding->next = newNode;
            newNode->previous = preceding;
            newNode->next = existing;
            existing->previous = newNode;           // Pointers are changed with respect to added node.

            this->currentSize = this->currentSize + 1;
        }
    }
    // Removes item from list
    int removeItem(int index){
        Node *toRemove = this->getNode(index);      // != nullptr

        Node *following = toRemove->next;
        if(following != nullptr){
            following->previous = toRemove->previous;
        } else {
            this->tail = toRemove->previous;        // No following node, so tail is removed.
        }
        Node *preceding = toRemove->previous;
        if(preceding != nullptr){
            preceding->next = toRemove->next;
        } else {
            this->head = toRemove->next;
        }
        this->currentSize = this->currentSize - 1;
        int removed = toRemove->data;
        delete(toRemove);
        return removed;
    }
    //setsItesm
    int setItem(int data, int index){
        struct Node *node = this->getNode(index);
        int old = node->data;
        node->data = data;
        return old;
    }

};
int main()
{
    try {
        MyLinkedList list; // No new keyword because "list" != pointer.
        list.display();
        cout << "Appending 3 items..." << endl;
        list.appendItem(23);
        list.appendItem(93);
        list.appendItem(46);

        list.display();
        cout << "Prepending 3 items..." << endl;
        list.prependItem(58);
        list.prependItem(75);
        list.prependItem(101);
        list.display();
    // Grey Bar
        cout << "Demonstrating getItem(1)..." << endl;
        cout << list.getItem(1) << endl;

        //cout << "Demonstrating getItem(10) [error]" << endl;      // If you want to demonstrate an error.
        //cout << list.getItem(10) << endl;

        cout << "Inserting at position 0..." << endl;
        list.insertItem(715, 0);
        cout << "Inserting at position 4..." << endl;
        list.insertItem(999, 4);
        list.display();
        cout << endl;

        cout << "Removing from position 0..." << endl;
        list.removeItem(0);
        list.display();
        cout << endl;
        cout << "Removing from position 2..." << endl;
        list.removeItem(2);
        list.display();
        cout << endl;
        cout << "Removing from position 3..." << endl;
        list.removeItem(3);
        list.display();
        cout << endl;

    } catch(const char *msg){
        cerr << msg << endl;
    }
    return 0;
}
