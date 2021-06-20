#include "include.h"

struct Node{
    int elem;
    Node* next;
};

class LinkedList{
    private:
        Node* head;
        int size;
    public:
        LinkedList();
        ~LinkedList();

        void add(int elem);
        void displayList();

        void reverse();     // reverse a linked list

        Node* getHead();
        int getSize();
};
