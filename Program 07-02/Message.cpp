#include "Message.h"
#include "User.h"

Message::~Message(){
	for (unsigned int i = 0; i < childList.size(); i++)
		delete childList[i];
}

const string& Message::getSubject() const{
	return subject;
}

unsigned Message::getID() const{
	return id;
}

void Message::addChild(Message* inChild){
	childList.push_back(inChild);
}

void Message::print(unsigned indentation) const{
	int count = indentation;
	string test;
	istringstream iss(body);
	
	if(indentation != 0) 
		cout << endl;
	
	for(int i = 0; i < count; ++i)
		cout << "  ";
	
	cout << "Message #" << id << ": " << subject << endl;
	
	for(int i = 0; i < count; ++i)
		cout << "  ";
	
	cout << "from " << author << ": ";

	getline(iss, test);
		cout << test << endl;

	while(getline(iss, test)){
		for(int i = 0; i < count; ++i)
			cout << "  ";
		cout << test << endl;
	}

	for(unsigned int i = 0; i < childList.size(); ++i)
		childList.at(i)->print(count + 1);
}

void Message::display() const{
		cout << this->subject << endl;
		cout << "from " << this->author << ": " << this->body << endl;
}
