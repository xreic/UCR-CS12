#ifndef REPLY_H
#define REPLY_H

#include <string>
#include <sstream>
#include <vector>

#include "Message.h"

using namespace std;

class Reply : public Message{
	public:
		Reply():Message(){
		}

		Reply(const string& author, const string& subject, const string& body, unsigned id)
			:Message(author, subject, body, id){
				childList.clear();
			}

		virtual bool isReply() const;

		virtual string toFormattedString() const;
};

#endif
