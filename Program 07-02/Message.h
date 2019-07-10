#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Message{
	protected:
		string author;
		string subject;
		string body;
		unsigned id;
		vector<Message* > childList;

	public:
		Message()
			: author(), subject(), body(), id(0){
			childList.clear();
		}

		Message(const string& author, const string& subject, const string& body, unsigned id)
			: author(author), subject(subject), body(body), id(id){
			childList.clear();
		}

		virtual ~Message();

		virtual bool isReply() const = 0;

		virtual string toFormattedString() const = 0;
		
		void print(unsigned indentation) const;

		const string& getSubject() const;

		unsigned getID() const;

		void addChild(Message* inChild);

		void display() const;
};
#endif
