#include "BBoard.h"
#include "User.h"

using namespace std;

BBoard::BBoard(){
	title = "";
	string inFile;
	User currentUser();
	vector<User> userList();
	vector<Message> messageList();
}

BBoard::BBoard(const string& title): title(title){
	string inFile;
	User currentUser();
	vector<User> userList();
	vector<Message> messageList();
}

bool BBoard::loadUsers(const string& file){
	ifstream fin;
	string uN, pW;
	this->inFile = file;
	
	fin.open(this->inFile);
	if(!fin.is_open()){
		return false;
	}
	
	while(fin >> uN && uN != "end"){
		fin >> pW;
		User user(uN, pW);
		userList.push_back(user);
	}
	
	fin.close();
	return true;
}

bool BBoard::login(){
	string inputUN, inputPW;
	User currentUser;
	
	cout << "Welcome to " << this->title << endl;
	cout << "Enter your username ('Q' or 'q' to quit): ";
	cin >> inputUN;
	cout << endl;
	
	if(inputUN == "q" || inputUN == "Q"){
		cout << "Bye!" << endl;
		return false;
	}
	else{
	 	cout << "Enter your password: ";
	 	cin >> inputPW;
		cout << endl;
	 	
	 	this->currentUser = User(inputUN, inputPW);
		if(this->currentUser.userExists(inputUN, inputPW, this->inFile)){
			cout << "Welcome back " << inputUN << "!" << endl << endl;
			return true;
		}
		else{
			while(!this->currentUser.userExists(inputUN, inputPW, this->inFile)){
				cout << "Invalid Username or Password!" << endl << endl;
				cout << "Enter your username ('Q' or 'q' to quit): ";
				cin >> inputUN;
				cout << endl;
				
				if(inputUN == "q" || inputUN == "Q"){
					cout << "Bye!" << endl;
					return false;
				}
				else{
					cout << "Enter your password: ";
				 	cin >> inputPW ;
				 	cout << endl;
				}
			}
			cout << "Welcome back " << inputUN << "!" << endl << endl;
			return true;
		}
	}
}

void BBoard::run(){
	int z = 0;
	Message messageList;
	string msgS, msgB;
	
	if(this->currentUser.getUsername() == "")
		return;
	
	char inputA;
		
	while(z == 0){
		cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Message ('N' or 'n')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
		cin >> inputA;
		cout << endl;
		
		if(inputA == 'q' || inputA == 'Q'){
			cout << "Bye!" << endl;
			z = 1;
		}
		else if(inputA == 'd' || inputA == 'D'){
			if(this->messageList.size() > 0)
				for(unsigned int i = 0; i < this->messageList.size(); ++i){
					if(i == 0)
						cout << "---------------------------------------------------------" << endl;
					cout << "Message #" << i + 1 << ": ";
					this->messageList.at(i).display();
					cout << "---------------------------------------------------------" << endl;
					if(i == this->messageList.size() - 1)
						cout << endl;
				}
			else
				cout << "Nothing to Display." << endl << endl;
		}
		else{
			cout << "Enter Subject: ";
			cin.ignore(1, '\n');
			getline(cin, msgS);
			cout << endl << "Enter Body: ";
			getline(cin, msgB);
			cout << endl;
			
			Message inML(this->currentUser.getUsername(), msgS, msgB);
			this->messageList.push_back(inML);
			
			cout << "Message Recorded!" << endl << endl;
		}
	}
	
	return;	
}
