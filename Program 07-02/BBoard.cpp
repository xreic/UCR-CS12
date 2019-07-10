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

BBoard::~BBoard(){
	for(unsigned int i = 0; i < messageList.size(); ++i)
		delete messageList[i];
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

bool BBoard::loadMessages(const string& file){
	ifstream fin;
	ostringstream oss;
	
	this->inFile = file;
	
	int totMessages;
	int msgCounter = 0;
	
	string key;
	
	string msgType;
	vector<string> msgList;
	
	string author;
	vector<string> aList;

	string iSubject, rSubject;
	vector<string> sList;
	
	string iBody, rBody;
	vector<string> bList;
	
	bool rOccur = false;

	int childID = 0;
	string tChild, rChild;
	vector<string> cList;
	
	unsigned tID;
	vector<unsigned> idList;
	
	fin.open(this->inFile);
	if(!fin.is_open()){
		cout << file << "cannot be opened.";
		return false;
	}
	
	fin >> totMessages;
	
	// cout << totMessages << endl;
	while(msgCounter < totMessages){
		while(fin >> key && key != "<end>"){
			// cout << "MSGCOUNTER: " << msgCounter << endl;
			if(key == "<begin_topic>"){
				// cout << "<begin_topic>" << endl;
				while(fin >> key && key != "<end>"){
					if(key == ":id:"){
						// cout << ":id: ";
						
						fin >> tID;
						idList.push_back(tID);
						
						// cout << idList.at(msgCounter) << endl;
					}
					else if(key == ":subject:"){
						// cout << ":subject: ";
						
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
						rSubject.resize(rSubject.size() - 1);
						sList.push_back(rSubject);
						
						// cout << sList.at(msgCounter) << endl;
							
						if(key == ":from:"){
							// cout << ":from: ";
							fin >> author;
							
							aList.push_back(author);
							// cout << aList.at(msgCounter) << endl;
						}
					}
					// else if(key == ":children:"){
					// 		cout << ":children: ";
					// 	while(fin >> childID){
					// 		oss << childID;
					// 		tChild = oss.str();
					// 		rChild += tChild + " ";
					// 		oss.str("");
					// 		oss.clear();
					// 	}
						
					// 	rChild.resize(rChild.size() - 1);
					// 	cList.push_back(rChild);
						
					// 	cout << cList.at(msgCounter) << endl;
					// 	fin.clear();
					// }
					else if(key == ":body:"){
						rOccur = true;
						
						// cout << ":body: ";
						string iBody = "";
						
						while(rOccur == true){
							getline(fin, key);

							if(key.at(0) == ' ')
								key.erase(key.begin(), key.begin() + 1);
							
							if(key == "<end>"){
								rOccur = false;
								iBody.erase(iBody.end() - 1, iBody.end());
								bList.push_back(iBody);
							}
							else
								iBody += key + "\n";
						}
						
						// cout << bList.at(msgCounter) << endl;
					}
					if(key == "<end>"){
						Topic* holder = new Topic(aList.at(msgCounter), sList.at(msgCounter), bList.at(msgCounter), idList.at(msgCounter));
						this->messageList.push_back(holder);
						// cout << "<end>" << endl;
						break;
					}
				}
				
				++msgCounter;
			}
			else if(key == "<begin_reply>"){
				// cout << "<begin_reply>" << endl;
				while(fin >> key && key != "<end>"){
					if(key == ":id:"){
						// cout << ":id: ";
						
						fin >> tID;
						idList.push_back(tID);
						
						// cout << idList.at(msgCounter) << endl;
					}
					else if(key == ":subject:"){
						// cout << ":subject: ";
						
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
						rSubject.resize(rSubject.size() - 1);
						sList.push_back(rSubject);
						
						// cout << sList.at(msgCounter) << endl;
							
						if(key == ":from:"){
							// cout << ":from: ";
							fin >> author;
							
							aList.push_back(author);
							// cout << aList.at(msgCounter) << endl;
						}
					}
					// else if(key == ":children:"){
					// 		cout << ":children: ";
					// 	while(fin >> childID){
					// 		oss << childID;
					// 		tChild = oss.str();
					// 		rChild += tChild + " ";
					// 		oss.str("");
					// 		oss.clear();
					// 	}
						
					// 	rChild.resize(rChild.size() - 1);
					// 	cList.push_back(rChild);
						
					// 	cout << cList.at(msgCounter) << endl;
					// 	fin.clear();
					// }
					else if(key == ":body:"){
						rOccur = true;
						
						// cout << ":body: ";
						string iBody = "";
						while(rOccur == true){
							getline(fin, key);

							if(key.at(0) == ' ')
								key.erase(key.begin(), key.begin() + 1);
							
							if(key == "<end>"){
								rOccur = false;
								iBody.erase(iBody.end() - 1, iBody.end());
								bList.push_back(iBody);
							}
							else
								iBody += key + "\n";
						}
						// cout << bList.at(msgCounter) << endl;
					}
					if(key == "<end>"){
						Reply* holder = new Reply(aList.at(msgCounter), sList.at(msgCounter), bList.at(msgCounter), idList.at(msgCounter));
						this->messageList.push_back(holder);
						// cout << "<end>" << endl;
						break;
					}
				}
				
				++msgCounter;
			}
		}
	}
	fin.close();
	
	fin.open(this->inFile);
	if(!fin.is_open()){
		cout << file << "cannot be opened.";
		return false;
	}
	
	msgCounter = 0;
	while(msgCounter < totMessages){
		while(fin >> key && key != "<end>"){
			if(key == ":id:")
				fin >> tID;

			else if(key == ":children:"){
				while(fin >> childID){
					this->messageList.at(msgCounter)->addChild(this->messageList.at(childID - 1));
				}
					
				fin.clear();
			}
		}
		++msgCounter;
	}
	
	return true;
}

bool BBoard::saveMessages(const string& file){
	ofstream fout;
	this->inFile = file;
	
	fout.open(this->inFile);
	if (!fout.is_open()){
		cout << file << "could not be opened." << endl;
		return false;
	}
	
	if(messageList.size() == 0)
		return false;
	
	fout << messageList.size() << "\n";
	
	for(unsigned int i = 0; i < messageList.size(); ++i){
		fout << messageList.at(i)->toFormattedString();
		fout << '\n';
	}
	
	fout.close();
	return true;
}

bool BBoard::login(){
	string inputUN, inputPW;
	bool userCheck = true;
	cout << "Welcome to " << this->title << endl;

	do{
		cout << "Enter your username ('Q' or 'q' to quit): ";
		cin >> inputUN;
		
		if(inputUN == "Q" || inputUN == "q"){
			cout << "Bye!" << endl;
			exit(0);
		}
		
		cout << "Enter your password: ";
		cin >> inputPW;
		cout << endl;
		
		if(getUser(inputUN, inputPW) == 0)
			cout << "Invalid Username or Password!" << endl << endl;
		else{
			currentUser = getUser(inputUN, inputPW);
			userCheck = false;
		}
	}while(userCheck);
	
	return true;
}

void BBoard::run(){
	int z = 0;
	
	if(this->currentUser->getUsername() == "")
		return;
	
	cout << "Welcome back " << this->currentUser->getUsername() << "!" << endl << endl;

	char inputA;
		
	while(z == 0){
		cout  << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Topic ('N' or 'n')" << endl << "- Add Reply to a Topic ('R' or 'r')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
		cin >> inputA;
		
		if(inputA == 'q' || inputA == 'Q'){
			cout << "Bye!" << endl;
			z = 1;
		}
		else if(inputA == 'd' || inputA == 'D')
			display();
		else if(inputA == 'r' || inputA == 'R')
			addReply();
		else if(inputA == 'n' || inputA == 'N')
			addTopic();
		// else
			// cout << endl;
	}
	return;	
}

const User* BBoard::getUser(const string& name, const string& password) const{
	for(unsigned int i = 0; i < userList.size(); ++i)
		if(userList.at(i).check(name, password))
			return &userList.at(i);
	
	return 0;
}

void BBoard::display() const{
	if(this->messageList.size() > 0){
		for(unsigned int i = 0; i < this->messageList.size(); ++i){
			if(i == 0)
				cout << endl;
			if(this->messageList.at(i)->isReply() == false){
				cout << "---------------------------------------------------------" << endl;
				messageList.at(i)->print(0);
			}
			
			
			if(i == this->messageList.size() - 1)
				cout << "---------------------------------------------------------" << endl << endl;
		}
	}
	else
		cout << endl << "Nothing to Display." << endl << endl;
}

void BBoard::addTopic(){
	string subject, body, result;
	
	cout << "Enter Subject: ";
	cin.ignore();
	getline(cin, subject);
	
	cout << "Enter Body: ";
	getline(cin, body);
	
	while(!body.empty()){
		result += body + '\n';
		getline(cin, body);
	}
	
	cout << endl;
	
	result.resize(result.size() - 1);
	
	Topic* holder = new Topic(this->currentUser->getUsername(), subject, result, messageList.size() + 1);
	this->messageList.push_back(holder);
}

void BBoard::addReply(){
	unsigned int sLoc = 1;
	int location = sLoc;
	string result, body, subject;
	bool locChecker = true;
	
	while(locChecker){
		cout << endl << "Enter Message ID (-1 for Menu): ";
		cin >> sLoc;

		if(sLoc <= messageList.size())
			locChecker = false;
		else{
			cout << "Invalid Message ID." << endl;
			return;
		}
		
		if(location < 0)
			locChecker = false;
	}
	
	cout << "Enter body: ";
	cin.ignore();
	getline(cin, body);
		
	while(!body.empty()){
		result += body + '\n';
		getline(cin, body);
	}
	
	result.resize(result.size() - 1);
	subject = "Re: ";
	subject += this->messageList.at(sLoc - 1)->getSubject();
	
	Reply* holder = new Reply(this->currentUser->getUsername(), subject, result, this->messageList.size() + 1);
	this->messageList.push_back(holder);
	
	int size = this->messageList.size();

	this->messageList.at(sLoc - 1)->addChild(this->messageList.at(size - 1));
	
	cout << "Message has been recorded." << endl;
}
