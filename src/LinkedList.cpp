#include "LinkedList.h"

LinkedList::LinkedList(){
    head=new Node();
    head->next=NULL;

    size=0;
}
LinkedList::~LinkedList(){
    // delete all elems in list
}

void LinkedList::add(int elem){
    Node* node=new Node();
    node->elem=elem;

    node->next=head->next;
    head->next=node;

    size++;
}

void LinkedList::reverse(){
    Node* prev;
    Node* curr;
    Node* next;

    //  initialize values 
    prev=NULL;          // this will represent the end of the list which will point to null
    curr=head->next;    // beginning of list
    next=head->next->next;  // 1 elem after beginning of list
    curr->next=prev;    // placed here to make the loop less confusing

    for(int i=0; i < (size-1) ;i++){    // size - 1 because the first iteration took place outside of loop
        prev=curr;
        curr=next;
        next=next->next;

        curr->next=prev;
    }

    head->next=curr;      // curr should end at the last elem in list
}

void LinkedList::displayList(){
    Node* curr=head;

    while(curr->next!=NULL){
        curr=curr->next;

        cout<<curr->elem<<",";
    }

    cout<<endl<<endl;
}

Node* LinkedList::getHead(){
    return head;
}
int LinkedList::getSize(){
    return size;
}



