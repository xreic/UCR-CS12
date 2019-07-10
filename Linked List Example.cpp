#include <iostream>
#include <cstdlib>
using namespace std;

class IntNode {
public:
    IntNode(int dataInit = 0, IntNode* nextLoc = 0);
    void InsertAfter(IntNode* nodePtr);
    IntNode* GetNext();
    void PrintNodeData();
    int GetDataVal();
private:
    int dataVal;
    IntNode* nextNodePtr;
};

// Constructor
IntNode::IntNode(int dataInit, IntNode* nextLoc) {
    this->dataVal = dataInit;
    this->nextNodePtr = nextLoc;
    return;
}

	/*
	Insert node after this node.
	Before: this -- next
	After:  this -- node -- next
	*/
 
void IntNode::InsertAfter(IntNode* nodeLoc) {
    IntNode* tmpNext = 0;
    
    tmpNext = this->nextNodePtr;			// Remember next
    this->nextNodePtr = nodeLoc;			// this -- node -- ?
    nodeLoc->nextNodePtr = tmpNext;			// this -- node -- next
    return;
}

// Print dataVal
void IntNode::PrintNodeData() {
    cout << this->dataVal << endl;
    return;
}

// Grab location pointed by nextNodePtr
IntNode* IntNode::GetNext() {
    return this->nextNodePtr;
}

int IntNode::GetDataVal() {
    return this->dataVal;
}

int main() {
    IntNode* headObj = 0;					// Create intNode objects (0 indicates NULL POINTER)
    IntNode* currObj = 0;
    IntNode* lastObj = 0;
    int i = 0;								// Loop index
    int min;								// Minimum value storage
    
    headObj = new IntNode(-1);				// Front of nodes list
    lastObj = headObj;
    
    for (i = 0; i < 20; ++i) {				// Append 20 rand nums
	  currObj = new IntNode(rand());
	  
	  lastObj->InsertAfter(currObj);		// Append curr
	  lastObj = currObj;					// Current object is the last object
    }
    
    currObj = headObj;						// Sets current object to the first pointer of the linked list (Not first useful value)
    currObj = currObj->GetNext();			// Directs current object to the first useful value of the linked list
    while (currObj != 0) {					// Looper stops when current object hits last object
	  currObj->PrintNodeData();
	  currObj = currObj->GetNext();
    }

	cout << endl;

    currObj = headObj;						// Print the list
    currObj = currObj->GetNext();
    min = currObj->GetDataVal();
    while (currObj != 0) {
        if(min > currObj->GetDataVal())
			min = currObj->GetDataVal();
		currObj = currObj->GetNext();
    }
    cout << endl << min << endl;
    
    return 0;
}
