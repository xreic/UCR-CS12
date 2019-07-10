#include "Message.h"
#include "User.h"

Message::Message(): author(), subject(), body(){
}

Message::Message(const string& athr, const string& sbjct, const string& body): author(athr), subject(sbjct), body(body){
}

void Message::display() const{
		cout << this->subject << endl;
		cout << "from " << this->author << ": " << this->body << endl;
}
