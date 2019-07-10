#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

void readData(string s, vector<double>& v1, vector<double>& v2);

double interpolation(double d, const vector<double>& v1, const vector<double>& v2);

bool isOrdered(const vector<double>& v1);

void reorder(vector<double>& v1, vector<double>& v2);

int main(){
	double interValue = 0.0;
	string fileName = "test";
	vector<double> fpa(0);
	vector<double> col(0);
	
	cout << "Enter name of input data file:";
	cin >> fileName;
	cout << endl << endl;
	
	readData(fileName, fpa, col);
	
	reorder(fpa, col);
	
	cout << "Enter the first flight path angle: ";
	cin >> interValue;
	cout << endl;
	
	cout << interpolation(interValue, fpa, col) << endl;
	
	return 0;
}

void readData(string s, vector<double>& v1, vector<double>& v2){
	int v = 0;
	double x = 0.0;
	ifstream fin;
	
	fin.open(s);
	if(!fin.is_open()){
		cout << "Error opening " << s << endl;
		exit(1);
	}
	
	while(fin >> x){
		if(v == 0){
			v1.push_back(x);
			v = 1;
		}
		else{
			v2.push_back(x);
			v = 0;
		}
	}
	
	return;
}

bool isOrdered(const vector<double>& v1){
	if(v1.size() > 0)
		for(unsigned int i = 0; i < v1.size() - 1; ++i)
			if (v1.at(i) > v1.at(i+1))
				return 0;
	
	return 1;
}

void reorder(vector<double>& v1, vector<double>& v2){
	if(!isOrdered(v1)){
		for(unsigned int i = 0; i < v1.size(); ++i)
			for(unsigned int j = 0; j < v1.size(); ++j)
				if(v1.at(i) < v1.at(j)){
					swap(v1.at(i), v1.at(j));
					swap(v2.at(i), v2.at(j));
				}
	}
	return;
}

double interpolation(double d, const vector<double>& v1, const vector<double>& v2){
	double colA, colB;
	int max = v1.size();
	double interp = 0.0;
	
	for(int i = max - 1; i > 0; --i)
		if (d == v1.at(i))
			return v2.at(i);

	for(int j = max - 1; j > 0; --j)
		if (d > v1.at(j)){
			colA = j;
			break;
		}
			
	for(int k = 0; k < max - 1; ++k)
		if (d < v1.at(k)){
			colB = k;
			break;
		}
		
	interp = (((d - v1.at(colA)) / (v1.at(colB) - v1.at(colA))) * (v2.at(colB) - v2.at(colA))) + v2.at(colA);
	
	return interp;
}
