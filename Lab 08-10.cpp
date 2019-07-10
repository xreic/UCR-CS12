#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int fileSum (string n);

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    cout << endl;
    cout << "Sum: " << fileSum(filename) << endl;
    
    return 0;
}

int fileSum (string n){
	int x, y = 0;
	ifstream fin;
	
	fin.open(n);
	if(!fin.is_open()){
		cout << "Error opening " << n << endl;
		exit(1);
	}
	
	while(fin >> x)
		y += x;
	
	fin.close();
	
	return y;
}
