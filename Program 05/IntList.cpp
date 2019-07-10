#include "IntList.h"

IntList::IntList(): head(0), tail(0){
}

IntList::~IntList(){
    while(head != 0)
        pop_front();
    if(head != tail)
        tail = head;
}

IntList::IntList(const IntList& cpy){
    this->head = cpy.head;

    return;
}

IntList& IntList::operator=(const IntList& rhs){
    if(this != &rhs){
        clear();
        for(IntNode* holder = rhs.head; holder != 0; holder = holder->next)
            push_back(holder->data);
    }
    return *this;
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

void IntList::push_back(int value){
    IntNode* holder = new IntNode(value);
    
    if(head == 0){
        head = holder;
        tail = head;
        return;
    }
    
    if(tail == head){
        tail = holder;
        head->next = tail;
        return;
    }
    
    tail->next = holder;
    tail = holder;
    return;
}

void IntList::clear(){
    while(head != 0)
        pop_front();
    if(head != tail)
        tail = head;
}

void IntList::selection_sort(){
    for(IntNode* firstObjLoop = head; firstObjLoop != 0; firstObjLoop = firstObjLoop->next){
        int min = firstObjLoop->data;
        IntNode* minAddress = firstObjLoop;
        
        for(IntNode* secondObjLoop = firstObjLoop->next; secondObjLoop != 0; secondObjLoop = secondObjLoop->next){
            if(min > secondObjLoop->data){
                min = secondObjLoop->data;
                minAddress = secondObjLoop;
            }
        }
        minAddress->data = firstObjLoop->data;
        firstObjLoop->data = min;
    }
}

void IntList::insert_ordered(int value){
    IntNode* holder = new IntNode(value);
    
    if(head == 0){
        head = holder;
        tail = head;
        return;
    }
    
    if(head == tail){
        if(head->data > holder->data){
            push_front(value);
            return;
        }
        else{
            head->next = holder;
            holder->next = tail;
            tail->next = 0;
            return;
        }
    }

    IntNode* previousAddress = head;
    for(IntNode* firstObjLoop = head; firstObjLoop != 0; firstObjLoop = firstObjLoop->next)
        if(firstObjLoop->data < holder->data)
            previousAddress = firstObjLoop;

    if(previousAddress == head){
        if(head->data > holder->data){
            holder->next = head;
            head = holder;
            return;
        }
        else{
            holder->next = head->next;
            head->next = holder;
            return;
        }
    }
    else if(previousAddress == tail){
        push_back(value);
        return;
    }
    else if(previousAddress->next == tail){
        holder->next = previousAddress->next;
        previousAddress->next = holder;
        return;
    }
    else{
        holder->next = previousAddress->next;
        previousAddress->next = holder;
        return;
    }
}

void IntList::remove_duplicates(){
	if(head == 0)
	    return;
	
	IntNode* dupeValue = 0;
	IntNode* previousAddress = head;
	
	for(IntNode* firstObjLoop = head; firstObjLoop != 0; firstObjLoop = firstObjLoop->next){
		dupeValue = firstObjLoop->next;
		previousAddress = firstObjLoop;
		
		while(dupeValue != 0){
			if (firstObjLoop->data == dupeValue->data){
				if(dupeValue == tail){
					dupeValue = 0;
					previousAddress->next = 0;
					tail = previousAddress;
				}
				else{
					previousAddress->next = dupeValue->next;
					dupeValue = dupeValue->next;
				}
			}
			else{
				dupeValue = dupeValue->next;
				previousAddress = previousAddress->next;
			}
		}
	}
}

ostream& operator<<(ostream& out, const IntList& rhs){
    for(IntNode* firstObjLoop = rhs.head; firstObjLoop != 0; firstObjLoop = firstObjLoop->next){
        out << firstObjLoop->data;
        if(firstObjLoop != rhs.tail)
            out << " ";
    }

    return out;
}
