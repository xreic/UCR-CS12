#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

using namespace std;

class Message{
	private:
		string author;
		string subject;
		string body;

	public:
		// Default constructor
		Message();
		
		// Constructor with parameters
		Message(const string& athr, const string& sbjct, const string& body);
		
		/*
		Displays the message in the given format. See output specs.
		Note: this function must output a single newline character at the end (after the body).
		*/
		void display() const;
};

#endif
