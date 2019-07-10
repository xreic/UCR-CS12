#include "IntVector.h"

int main(){
	unsigned int size, value, index = 0;

	cout << "Size: ";
	cin >> size;
	cout << "Value: ";
	cin >> value;
	
	
	cout << endl << "~Default Constructor." << endl;
	IntVector* myVector;
	myVector = new IntVector();
	
	cout << "Size: " << myVector->size() << endl;
	cout << "Capacity: " << myVector->capacity() << endl << endl;
	
	cout << "~Empty" << endl;
	if(myVector->empty())
		cout << "Is Empty" << endl;
	else
		cout << "Is Not Empty" << endl;
	cout << "~Complete." << endl << endl;
	
	delete myVector;
	cout << "~Default Constructor End." << endl << endl;
	
	
	cout << "~Second Constructor." << endl;
	myVector = new IntVector(size, value);
	
	cout << "Size: " << myVector->size() << endl;
	cout << "Capacity: " << myVector->capacity() << endl << endl;
	delete myVector;
	
	
	cout << "~Empty" << endl;
	cout << "  Checks if vector is empty or not." << endl;
	myVector = new IntVector(size, value);
	if(myVector->empty())
		cout << "Is Empty" << endl;
	else
		cout << "Is Not Empty" << endl;
	delete myVector;
	cout << "~Complete." << endl << endl;
	
	
	cout << "~At" << endl;
	cout << "  Outputs entire vector." << endl;
	myVector = new IntVector(size, value);
	for(unsigned int i = 0; i < myVector->size(); ++i)
		cout << myVector->at(i) << " ";
	cout << endl;
	delete myVector;
	cout << "~Complete." << endl << endl;
	
	
	cout << "~Front" << endl;
	cout << "  Outputs first value in vector." << endl;
	myVector = new IntVector(size, value);
	cout << myVector->front() << endl;
	delete myVector;
	cout << "~Complete." << endl << endl;
	
	
	cout << "~Back" << endl;
	cout << "  Outputs last value in vector." << endl;
	myVector = new IntVector(size, value);
	cout << myVector->back() << endl;
	delete myVector;
	cout << "~Complete." << endl << endl;
	
	
	cout << "~Out of Range At:" << endl;
	cout << "  Test for out of range, if a valid index is entered then the value will be reported." << endl;
	myVector = new IntVector(size, value);
	cout << "Max index of current vector: " << myVector->size() - 1 << endl;
	cout << "Enter index value to test: ";
	cin >> index;
	cout << myVector->at(index) << endl;
	delete myVector;
	cout << "~Complete." << endl << endl;

	
	cout << "Second Constructor End." << endl << endl;
	
	return 0;
}
