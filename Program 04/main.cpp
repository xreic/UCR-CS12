#include "IntVector.h"

int main(){
	unsigned int size, value;
	unsigned int insertValue, index, z;
	// unsigned int eraseIndex;
	// unsigned int assignSize, assignValue;
	// unsigned int pushBack;
	// unsigned int resizeSize, resizeValue;

	/*
	cout << endl << "Default Constructor." << endl;
	IntVector* myVector;
	myVector = new IntVector();
	
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	
	cout << "Empty" << endl;
	if(myVector->empty())
		cout << "  Vector is empty." << endl;
	else
		cout << "  Vector is not empty." << endl;
	cout << "~Default Constructor End." << endl << endl << endl;
	*/
	/*
	cout << "Second Constructor." << endl << endl;
	
	cout << "Empty" << endl;
	cout << "  Checks if vector is empty or not." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	if(myVector->empty())
		cout << "  Vector is empty." << endl;
	else
		cout << "  Vector is not empty." << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "At" << endl;
	cout << "  Outputs entire vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Vector is: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Front" << endl;
	cout << "  Outputs first value in vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << myVector->front() << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Back" << endl;
	cout << "  Outputs last value in vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << myVector->back() << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Out of Range At:" << endl;
	cout << "  Test for out of range, if a valid index is entered then the value will be reported." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "  Enter index value to test: ";
	cin >> index;
	cout << "  Value at indicated index: " << myVector->at(index) << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Insert" << endl;
	cout << "  Inserts a value at a designated location in the vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "  Enter value to be inserted: ";
	cin >> insertValue;
	cout << "  Enter index for the value to be inserted at: ";
	cin >> index;
	cout << "  Array before insertion: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	myVector->insert(index, insertValue);
	cout << "  Array after insertion:  ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Erase" << endl;
	cout << "  Erases a value at a designated location in the vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "  Enter index to be erased: ";
	cin >> eraseIndex;
	cout << "  Array before erase: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	myVector->erase(eraseIndex);
	cout << "  Array after erase:  ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Assign" << endl;
	cout << "  Assigns the vector a new size and values." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "  Enter size of the new vector: ";
	cin >> assignSize;
	cout << "  Enter value to be assigned to new vector: ";
	cin >> assignValue;
	cout << "  Array before assignment: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	myVector->assign(assignSize, assignValue);
	cout << "  Array after assignment:  ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Push Back" << endl;
	cout << "  Appends the value to the end of the vector." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Enter value to be appended: ";
	cin >> pushBack;
	cout << "  Array before pushback: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	myVector->push_back(pushBack);
	cout << "  Array after pushback:  ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Resize" << endl;
	cout << "  Resizes the vector to a new length, if new locations in memory are created then a values is set to those locations." << endl;
	cout << "  Size: ";
	cin >> size;
	cout << "  Value: ";
	cin >> value;
	myVector = new IntVector(size, value);
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "  Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "  Enter size of the new vector: ";
	cin >> resizeSize;
	cout << "  Enter value(s) to be assigned to new vector: ";
	cin >> resizeValue;
	cout << "  Array before resize: ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	myVector->resize(resizeSize, resizeValue);
	cout << "  Array after resize:  ";
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	//delete [] myVector;
	cout << endl << "  Current Size: " << myVector->size() << endl;
	cout << "  Current Capacity: " << myVector->capacity() << endl << endl;
	cout << "~Complete." << endl << endl;
	
	
	cout << "Second Constructor End." << endl << endl;
	*/
	
	cout << "Size: ";
	cin >> size;
	cout << "Value: ";
	cin >> value;
	
	IntVector* myVector;
	myVector = new IntVector(size, value);
	
	cout << "Current Size: " << myVector->size() << endl;
	cout << "Current Capacity: " << myVector->capacity() << endl << endl;
	
	while(cin >> z){
		cout << endl << "Enter value to be inserted: ";
		cin >> insertValue;
		cout << endl;
		cout << "Enter index for value to be inserted at: ";
		cin >> index;
		cout << endl;
		cout << "Current Size: " << myVector->size() << endl;
		cout << "Current Capacity: " << myVector->capacity() << endl;
		
		myVector->insert(insertValue, myVector->at(index));
		
		for(unsigned int i = 0; i < myVector->size(); ++i)
			cout << myVector->at(i) << " ";
		cout << endl;
	}
		
	return 0;
}
