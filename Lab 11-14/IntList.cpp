#include "IntList.h"

IntList::IntList(): head(0), tail(0){
}

IntList::~IntList(){
    while(head != 0)
        pop_front();
}

void IntList::display() const{
    IntNode* currObj;                   // Creates current object
    currObj = head;                     // Sets current object to head
    
    while (currObj != 0) {              // Loop to go through entire list
        cout << currObj->data;          // Outputs the value of integer data
	    currObj = currObj->next;        // Sets the next object as the new current object
	    if(currObj != 0)                // Space is outputted, while the current object is not "tail"
	        cout << " ";
    }
}

void IntList::push_front(int value){
    IntNode* holder = new IntNode(value);       // New pointer of IntNode is made and allocated with data set as "value"
    holder->next = head;                        // holder->next stores the address of "head"
    head = holder;                              // Assigns holder to head
    
    if(tail == 0)
        tail = holder;
}

void IntList::pop_front(){
    if(head == 0)
        return;
        
    IntNode* holder = head;
    head = head->next;
    delete holder;
    
    if(head == 0)
        tail = 0;
}

bool IntList::empty() const{
    if(head == 0)
        return true;
    return false;
}
