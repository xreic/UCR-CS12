#include "User.h"

User::User(): username(), password(){
}

User::User(const string& username, const string& password): username(username), password(password){
}

string User::getUsername() const{
    return this->username;
}

string User::getPassword() const{
    return password;
}

bool User::check(const string& username, const string& password) const{
    if(username == "")
        return false;
    else if(this->username == username && this->password == password)
        return true;
    else
        return false;
}

bool User::setPassword(const string& oldPassword, const string& newPassword){
    if(this->username == "")
        return false;
    if (this->password == oldPassword){
        this->password = newPassword;
        return true;
    }
    else
        return false;
}

/*
bool User::userExists(const string& username, const string& password, const string& file) const{
	ifstream fin;
	string input;
	vector<string> ueN;
	vector<string> ueP;
	
	fin.open("Users.dat");
	if(!fin.is_open()){
		cout << file << " cannot be opened." << endl;
		return false;
	}
	
	while(fin >> input && input != "end"){
		ueN.push_back(input);
		fin >> input;
		ueP.push_back(input);
	}
	
	for(unsigned int i = 0; i < ueN.size(); ++i)
		if(ueN.at(i) == username && ueP.at(i) == password)
		    return true;
			
	return false;
}
*/
