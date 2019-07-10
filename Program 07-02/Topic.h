#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <sstream>
#include <vector>

#include "Message.h"

using namespace std;

class Topic : public Message{
	public:
		Topic():Message(){
			}

		Topic(const string& author, const string& subject, const string& body, unsigned id)
			: Message(author, subject, body, id){
			}

		virtual bool isReply() const;

		virtual string toFormattedString() const;
};
#endif
