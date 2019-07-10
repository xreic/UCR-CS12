#ifndef BBOARD_H
#define BBOARD_H

#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"

using namespace std;

class BBoard {
	private:
		string title;
		string inFile;
		const User* currentUser;
		vector<User> userList;
		vector<Message* > messageList;

	 public:
		BBoard();
	
		BBoard(const string& title);
		
		~BBoard();
	
		bool loadUsers(const string& file);

		bool loadMessages(const string& file);
		
		bool saveMessages(const string& file);

		bool login();
	
		void run();

	private:
		void addMessage();
		
		const User* getUser(const string& name, const string& password) const;
		
		void display() const;
		
		void addTopic();
		
		void addReply();
};
#endif
