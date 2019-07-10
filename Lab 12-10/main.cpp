#include <iostream>
#include <string>

using namespace std;

void flipString(string& s);

int main(){
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string& s){
    if(s.size() <= 1)
        return;
    else{
        char tempChar = s.at(0);
        s.erase(0, 1);
        flipString(s);
        s.push_back(tempChar);
    }
    
    return;
}
