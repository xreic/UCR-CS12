#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

class IntVector{
	private:
		unsigned sz;
		unsigned cap;
		int* data;
   
	public:
		IntVector();
		IntVector(unsigned size, int value = 0);
		~IntVector();
		unsigned size() const;
		unsigned capacity() const;
		bool empty() const;
		const int& at(unsigned index) const;
// 		int& at(unsigned index);
// 		void insert(unsigned index, int value);
// 		void erase(unsigned index);
		const int& front() const;
// 		int& front();
		const int& back() const;
// 		int& back();
// 		void assign(unsigned n, int value);
// 		void push_back(int value);
// 		void pop_back();
// 		void clear();
// 		void resize(unsigned size, int value = 0);
// 		void reserve(unsigned n);
		
// 		void list() const;
// 	private:
// 		void expand();
// 		void expand(unsigned amount);
};
#endif
