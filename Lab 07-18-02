#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const double pi = 3.14159265;

bool isInside(double x, double y, double r){
   double circleRadius = 0.0;
   double dartDist = 0.0;
   
   circleRadius = r / 2;
   dartDist = sqrt(pow(x, 2) + pow(y, 2));
   
   if (circleRadius >= dartDist)
      return 1;
   else
      return 0;
}

bool throwDart(int s){
   int x, y;
   x = ((rand() % (s + 1)) - (s / 2));
   y = ((rand() % (s + 1)) - (s / 2));
   
   return isInside(x, y, s);
}

int main(){
   srand(333);
   int side;
   int tries;
   
   cout << "Please enter the size of a side of the square (integers only)." << endl;
   cin >> side;
   cout << endl << "How many tries would you like to have?" << endl;
   cin >> tries;
   cout << endl;
   
   int inCount = 0;
   
   for(int i = 0; i < tries; ++i){
      if (throwDart(side))
         inCount = inCount + 1;
   }
   
   cout << "The value of pi is " << (4.0 * inCount) / tries << endl;
   
   return 0;
}
