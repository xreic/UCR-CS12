#include "IntVector.h"

IntVector::IntVector(): sz(0), cap(0), data(NULL){
}

IntVector::IntVector(unsigned size, int value): sz(size), cap(size){
	data = new int[size];
	
	for(unsigned int i = 0; i < size; ++i)
		data[i] = value;
}

IntVector::~IntVector(){
	delete [] data;
}

unsigned IntVector::size() const{
	return sz;
}

unsigned IntVector::capacity() const{
	return cap;
}

bool IntVector::empty() const{
	if(sz == 0)
		return true;
	else
		return false;
}

const int& IntVector::at(unsigned index) const{
	if(index >= sz)
		throw out_of_range("IntVector::at_range_check");
	return data[index];
}
/*
int& IntVector::at(unsigned index){
	if(index >= sz)
		throw out_of_range("IntVector::at_range_check");
	return data[index];
}

void IntVector::insert(unsigned index, int value){
	sz += 1;
	if(index >= sz)
		throw out_of_range("IntVector::insert_range_check");
	
	if(sz > cap)
		expand();
	
	for(unsigned i = index; i < sz; ++i)
		data[i + 1] = data[i];
	
	data[index] = value;
}

void IntVector::erase(unsigned index){
	if(index >= sz)
		throw out_of_range("IntVector::erase_range_check");
	
	for(unsigned int i = index; i < sz; ++i)
		data[i] = data[i + 1];
	sz -= 1;
}
*/
const int& IntVector::front() const{
	return data[0];
}
/*
int& IntVector::front(){
	return data[0];
}
*/
const int& IntVector::back() const{
	return data[sz - 1];
}
/*
int& IntVector::back(){
	return data[sz - 1];
}

void IntVector::assign(unsigned n, int value){
	while(cap < n){
		if((2 * cap) >= (n - cap))
			expand();
		else
			expand(n - cap);
		if(cap < n)
			cap = n;
	}
	
	sz = n;

	for(unsigned int i = 0; i < sz; ++i)
		data[i] =  value;
}

void IntVector::push_back(int value){
	sz += 1;
	if(sz >= cap)
		expand();
	
	data[sz - 1] = value;
}

void IntVector::pop_back(){
	sz -= 1;
}

void IntVector::clear(){
	sz = 0;
}

void IntVector::resize(unsigned size, int value){
	if(size > sz){
		if(size < cap)
			for(unsigned int i = sz; i < size; ++i)
				data[i] = value;
		else{ //(size >= cap)
			if((2 * cap) >= (size - cap))
				expand();
			else
				expand(size - cap);
				
			if(size > cap)
				cap = size;
				
			for(unsigned int i = sz; i < size; ++i)
				data[i] = value;
		}
	}
	else{ //(size <= sz)
		sz = size;
		for(unsigned int i = sz; i < size; ++i)
			data[i] = value;
	}
	
	sz = size;
}

void IntVector::reserve(unsigned n){
	if(cap > n)
		return;
	else if(cap == n)
		return;
	else{ // cap < n
		if((2 * cap) >= (n - cap))
			expand();
		else
			expand(n - cap);
		
		if(n > cap)
			cap = n;
	}
		
}

void IntVector::expand(){
	cap += cap;
	if(cap == 0)
		cap = 1;
	
	// cout << "Output data before:  ";
	// for(unsigned int i = 0; i < sz - 1; ++i)
	// 	cout << data[i] << " ";
	// cout << endl;
	
	int* nData = new int[cap];
	for(unsigned int i = 0; i < sz; ++i)
		nData[i] = data[i];
	
	// cout << "Output nData:        ";
	// for(unsigned int i = 0; i < sz; ++i)
	// 	cout << data[i] << " ";
	// cout << endl;

	data = nData;
	
	// cout << "Output data after:   ";
	// for(unsigned int i = 0; i < sz; ++i)
	// 	cout << data[i] << " ";
	// cout << endl;

	
	// delete [] nData;
}

void IntVector::expand(unsigned amount){
	cap += amount;
	
	int* nData = new int[cap];
	for(unsigned int i = 0; i < sz; ++i)
		nData[i] = data[i];
		
	// delete [] data;
	data = nData;
}

void IntVector::list() const{
	for(unsigned int i = 0; i < sz; ++i)
		cout << data[i] << " ";
	cout << endl;
}
*/
