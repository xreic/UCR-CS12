#include "Reply.h"

bool Reply::isReply() const{
	return true;
}

string Reply::toFormattedString() const{
	ostringstream oss;
	
	string tempSubject = getSubject();
	tempSubject.erase(tempSubject.begin(), tempSubject.begin() + 4);
	string result = "<begin_reply>";
	
	oss << id;
	result += "\n:id: " + oss.str();
	oss.str("");
	oss.clear();
	result += "\n:subject: " + getSubject();
	result += "\n:from: " + author;
	
	if(childList.size() != 0){
		result += "\n:children: ";
		for(unsigned int i = 0; i < childList.size(); i++){
			// cout << childList.at(i)->getID() << endl;
			oss.str("");
			oss.clear();
			oss << childList.at(i)->getID();
			result += oss.str() + " ";
			oss.str("");
			oss.clear();
		}
		result.resize(result.size() - 1);
	}
	
	result += "\n:body: " + body + "\n<end>";
	
	return result;
}
