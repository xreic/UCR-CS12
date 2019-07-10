#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;
 
class User{
	private:
		string username;
		string password;

	public:
		//creates a user with empty name and password.
		User();
		
		// creates a user with given username and password.
		User(const string& username, const string& password);
		
		// returns the username
		string getUsername() const;
		
		string getPassword() const;

		// returns true if the stored username/password matches with the
		// parameters. Otherwise returns false.
		// Note that, even though a User with empty name and password is 
		// actually a valid User object (it is the default User), this 
		// function must still return false if given a empty uname string.
		bool check(const string& username, const string& password) const;
		
		// sets a new password.
		// This function should only set the new password if the current (old) 
		// password is passed in. Also, a default User cannot have its 
		// password changed. 
		// returns true if password changed, false if not.
		bool setPassword(const string& oldPassword, const string& newPassword);

		// bool userExists(const string& username, const string& password, const string& file) const;
};

#endif
