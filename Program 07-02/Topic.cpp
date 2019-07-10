#include "Topic.h"

bool Topic::isReply() const{
	return false;
}

string Topic::toFormattedString() const{
	ostringstream oss;
	
	string result = "<begin_topic>";
	
	oss << id;
	result += "\n:id: " 		+ oss.str();
	oss.str("");
	oss.clear();
	result += "\n:subject: "	+ getSubject();
	result += "\n:from: "		+ this->author;
	
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

	result += "\n:body: "		+ body		+ "\n<end>";

	return result;
}
