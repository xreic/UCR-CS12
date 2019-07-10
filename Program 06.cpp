#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int x, int y);

bool diophantine(int a, int b, int c, int& x, int& y);

int main(){
	
	int a, b, c, x, y;

	cout << "Enter a b c" << endl;
	cin >> a >> b >> c;
	cout << endl;

	cout << "Result: ";
	
	if (diophantine(a, b, c, x, y))
		cout << x << " " << y << endl;
	else
		cout << "No solution!" << endl;

	return 0;
}

int gcd(int x, int y){
	// cout << "Entered GCD." << endl;
	int gcdValue;
	
	if(x == y){
		// cout << "Entered GCD case 1." << endl;
		gcdValue = x;
	}
	else{
		if(x > y){
			// cout << "Entered GCD case 2." << endl;
			gcdValue = gcd(abs(x) - abs(y), abs(y));
		}
		else{
			// cout << "Entered GCD case 3." << endl;
			gcdValue = gcd(abs(x), abs(y) - abs(x));
		}
	}
	
	return gcdValue;
}

bool diophantine(int a, int b, int c, int& x, int& y){
	// cout << endl << "Entered function." << endl;
	if(c % gcd(a, b) != 0){
		// cout << "Entered case 1." << endl;
		return false;
	}
	else if(a % b == 0){
		// cout << "Entered case 2." << endl;
		x = 0;
		y = c / b;
		return true;
	}
	else{
		// cout << "Entered case 3." << endl;
		int q = a / b;
		int r = a % b;
		int u = (q * x) + y;
		int v = x;
		
		if(diophantine(b, r, c, u, v)){
			// cout << "Entered recursion." << endl;
			x = v;
			y = u - q * x;
			return true;
		}
		return false;
	}	
}
