#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>

#include "User.h"
#include "Message.h"
//#include "Reply.h"
//#include "Topic.h"


using namespace std;

class BBoard
{
	private:
		string title;
		vector<User> user_list;
		const User* current_user;
		vector<Message*> message_list;
	public:
		BBoard();
		BBoard(const string &ttl);
		~BBoard();
		void load_users (const string &userfile);
		bool load_messages(const string& datafile);
		bool save_messages(const string& datafile);
		void login();
		void run();
	private:
		void add_user(const string &name, const string &pass);
		//bool user_exists(const string &name, const string &pass) const;
		const User* get_user(const string &name, const string &pw) const;
		void display() const;
		//void add_message();
		void add_topic();
		void add_reply();
		void create_body(string &finalBody);
};

#endif
