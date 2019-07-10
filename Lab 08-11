#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int charCnt (string fn, char c);


int main() {
   string filename;
   char ch;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin >> ch;
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

int charCnt (string fn, char c){
   int i = 0;
   char c2 = 'c';
   ifstream fin;
   
   fin.open(fn);
   if(!fin.is_open()){
      cout << "Error opening " << fn << endl;
      exit (EXIT_FAILURE);
      return 1;
   }
   
   while(fin >> c2)
      if(c == c2)
         i = i + 1;
   
   fin.close();
   
   return i;
}
