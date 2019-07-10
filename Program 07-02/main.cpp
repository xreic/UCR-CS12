#include <iostream>
#include <string>

using namespace std;

#include "BBoard.h"

int main(){
    string userfile;
    string datafile;
    
    cout << "User file?" << endl;
    cin >> userfile;
    cout << endl;

    cout << "Message file?" << endl;
    cin >> datafile;
    cout << endl;

    BBoard bb("CS12 Bulletin Board");
   
    if(!bb.loadUsers(userfile)){
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
   
    if(!bb.loadMessages(datafile)){
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
   
    bb.login();
    bb.run();

    if(!bb.saveMessages(datafile)){
        cout << "ERROR: Cannot save messages to zzMSG.txt" << endl;
        return 1;
    }
	
	exit(0);
}
