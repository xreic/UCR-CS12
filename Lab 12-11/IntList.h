#include "IntList.h"

IntList::IntList(): head(0){
}

void IntList::push_front(int value){
    IntNode* holder = new IntNode(value);       // New pointer of IntNode is made and allocated with data set as "value"
    holder->next = head;                        // holder->next stores the address of "head"
    head = holder;                              // Assigns holder to head
}

bool IntList::exists(int value) const{
    if(head == 0)
        return false;
    else if (head->data == value)
        return true;
    else
        return exists(head->next, value);
}

ostream& operator<<(ostream& out, const IntList& rhs){
    if(rhs.head == 0)
        return out;
        
    operator<<(out, rhs.head);
    
    return out;
}

bool IntList::exists(IntNode* startingValue, int value) const{
    if(startingValue == 0)
        return false;
    else if(startingValue->data == value)
        return true;
    else
        return exists(startingValue->next, value);
}

ostream& operator<<(ostream& out, IntNode* rhs){
    if(rhs == 0)
        return out;
    
    out << rhs->data;
    if(rhs->next != 0)
        out << " ";
    
    operator<<(out, rhs->next);

    return out;
}
