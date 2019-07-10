	/*
	while(msgCounter < totMessages){
		while(fin >> key){
			if(key == "<begin_topic>"){
				while(fin >> key){
					if(key == ":id:")
						fin >> tID;
					
					else if(key == ":subject:"){
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
							rSubject.resize(rSubject.size() - 1);
							
						if(key == ":from:")
						   fin >> author;
					}
					
					else if(key == ":body:"){
						bool rOccur = true;
						string iBody = "";
						
						while(rOccur){
							getline(fin, key);
							
							if(key != "<end>")
								iBody += key + "\n";
							else{
								iBody.resize(iBody.size() - 1);
								rOccur = false;
							}
						}
					}
					else if(key == "<end>"){
						Topic* holder = new Topic(author, rSubject, iBody, tID);
						this->messageList.push_back(holder);
						break;
					}
				}
			}
			else{ // key == "<begin_reply>"
				while(fin >> key){
					if(key == ":id:")
						fin >> tID;
					
					else if(key == ":subject:"){
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
							rSubject.resize(rSubject.size() - 1);
							
						if(key == ":from:")
						   fin >> author;
					}
					
					else if(key == ":body:"){
						bool rOccur = true;
						string iBody = "";
						
						while(rOccur){
							getline(fin, key);
							
							if(key != "<end>")
								iBody += key + "\n";
							else{
								iBody.resize(iBody.size() - 1);
								rOccur = false;
							}
						}
					}
					else if(key == "<end>"){
						Reply* holder = new Reply(author, rSubject, iBody, tID);
						this->messageList.push_back(holder);
						break;
					}
				}
			}
		}
	}
	
	fin.close();
	
	fin.open("zzMSG.txt");
	if(!fin.is_open){
		cout << file << "cannot be opened." << endl;
		return false;
	}
	
	fin >> totMessages;
	
	msgCounter = 0;
	while(msgCounter < totMessages){
		while(fin >> key){
			if(key == ":id:")
				fin >> msgCounter;
			else if(key == ":children:"){
				while(fin >> childID)
					this->messageList.at(msgCounter)->addChild(this->messageList.at(childID));
				
				fin.clear();
			}
		}
	}
	*/
	/*
	while(msgCounter < totMessages){
		while(fin >> key){
			if(key == "<begin_topic>"){
				cout << "Entered <begin_topic>" << endl;
				cout << "Curent msgCounter: " << msgCounter << endl << endl;
				while(fin >> key){
					if(key == ":id:"){
						fin >> tID;
						idList.push_back(tID);
						fin.clear();
					}
					else if(key == ":subject:"){
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
						rSubject.resize(rSubject.size() - 1);
						sList.push_back(rSubject);
							
						if(key == ":from:")
							fin >> author;
							
						aList.push_back(author);
					}
					
					else if(key == ":body:"){
						string iBody = "";
						
						while(rOccur){
							getline(fin, key);
							
							if(key != "<end>")
								iBody += key + "\n";
							else{
								iBody.resize(iBody.size() - 1);
								bList.push_back(iBody);
								rOccur = false;
							}
						}
					}
					
					if(rOccur == false)
						break;
				}
				
				++msgCounter;
			}
			else if(key == "<begin_reply>"){ // key == "<begin_reply>"
			cout << "Entered <begin_reply>" << endl;
			cout << "Curent msgCounter: " << msgCounter << endl << endl;
				while(fin >> key){
					if(key == ":id:"){
						fin >> tID;
						idList.push_back(tID);
					}
					else if(key == ":subject:"){
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
							rSubject.resize(rSubject.size() - 1);
							sList.push_back(rSubject);
							
						if(key == ":from:")
							fin >> author;
							
						aList.push_back(author);
					}
					
					else if(key == ":body:"){
						rOccur = true;
						string iBody = "";
						
						while(rOccur){
							getline(fin, key);
							
							if(key != "<end>")
								iBody += key + "\n";
							else{
								iBody.resize(iBody.size() - 1);
								bList.push_back(iBody);
								rOccur = false;
							}
						}
					}
					
					if(rOccur == false)
						break;
				}
				
				++msgCounter;
			}
		}
	}
	*/
	/*
	while(msgCounter < totMessages){
		while(fin >> key && key != "<end>"){
			if(key == "<begin_topic>"){
				cout << "Entered <begin_topic>" << endl;
				cout << "Current msgCounter: " << msgCounter << endl << endl;
				
				while(fin >> key && key != "<end>"){
					if(key == ":id:"){
						cout << "Read :id: ";
						
						fin >> tID;
						idList.push_back(tID);
						
						cout << idList.at(msgCounter) << endl;
					}
					else if(key == ":subject:"){
						cout << "Read :subject: ";
						
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
						rSubject.resize(rSubject.size() - 1);
						sList.push_back(rSubject);
						
						cout << sList.at(msgCounter) << endl;
							
						if(key == ":from:"){
							cout << "Read :from: ";
							fin >> author;
							
							aList.push_back(author);
							cout << aList.at(msgCounter) << endl;
						}
					}
					// else if(key == ":body:"){
					// 	cout << "Read :body: " << endl;
					// 	string iBody = "";
						
					// 	rOccur = true;
						
					// 	while(rOccur){
					// 		getline(fin, key);
							
					// 		if(key != "<end>"){
					// 			iBody += key + "\n";
					// 		}
					// 		else{
					// 			iBody.resize(iBody.size() - 1);
					// 			iBody.erase(iBody.begin(), iBody.begin() + 1);
					// 			bList.push_back(iBody);
					// 			rOccur = false;
					// 		}
					// 	}
					// 	cout << bList.at(msgCounter) << endl << endl;
					// }
				}
				++msgCounter;
			}
			else if(key == "<begin_reply>"){
				cout << "Entered <begin_reply>" << endl;
				cout << "Current msgCounter: " << msgCounter << endl << endl;
				
				while(fin >> key && key != "<end>"){
					if(key == ":id:"){
						cout << "Read :id: ";
						
						fin >> tID;
						idList.push_back(tID);
						
						cout << idList.at(msgCounter) << endl;
					}
					else if(key == ":subject:"){
						cout << "Read :subject: ";
						
						rSubject = "";
						while(fin >> key && key != ":from:")
							rSubject += key + " ";
							
						rSubject.resize(rSubject.size() - 1);
						sList.push_back(rSubject);
						
						cout << sList.at(msgCounter) << endl;
							
						if(key == ":from:"){
							cout << "Read :from: ";
							fin >> author;
							
							aList.push_back(author);
							cout << aList.at(msgCounter) << endl;
						}
					}
					// else if(key == ":body:"){
					// 	// cout << "Read :body: " << endl << endl;
					// 	cout << "Read :body: " << endl;
					// 	string iBody = "";
					// 	rOccur = true;
						
					// 	while(rOccur){
					// 		getline(fin, key);
							
					// 		if(key != "<end>")
					// 			iBody += key + "\n";
					// 		else{
					// 			iBody.resize(iBody.size() - 1);
					// 			iBody.erase(iBody.begin(), iBody.begin() + 1);
					// 			bList.push_back(iBody);
					// 			rOccur = false;
					// 		}
					// 	}
						
					// 	cout << bList.at(msgCounter) << endl << endl;
					// }
				}
				
				++msgCounter;
			}
		}
	}
	*/
