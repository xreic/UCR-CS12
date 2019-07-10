#include <iostream>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);

int main(){
    int i = 0, removal;
    int ARRAY_SIZE = 10;
    double uArray[ARRAY_SIZE];
    
    cout << "Enter 10 values:" << endl;
    while(cin >> uArray[i] && i < ARRAY_SIZE - 1)
        ++i;

    cout << endl << "Mean: " << mean(uArray, ARRAY_SIZE) << endl << endl;

    cout << "Enter index of value to be removed: ";
    cin >> removal;
    cout << endl;
    
    cout << "Before removing value: ";
    display(uArray, ARRAY_SIZE);
    cout << endl;

    remove(uArray, ARRAY_SIZE, removal);
    
    cout << "After removing value: ";
    display(uArray, ARRAY_SIZE);
    cout << endl;
    
    return 0;
}

double mean(const double array[], int arraySize){
    double sum = 0.0;
    double size = arraySize + 0.0;
    for(int i = 0; i < arraySize; ++i)
        sum += array[i];
    
    
    return sum/size;
}

void display(const double array[], int arraySize){
    for(int i = 0; i < arraySize; ++i){
        cout << array[i];
        if(i != arraySize - 1)
            cout << ", ";
    }
}

void remove(double array[], int& arraySize, int index){
    if((index > 0 && index < arraySize) && index == arraySize - 1){
        arraySize -= 1;
        return;
    }
    else{
        for(int i = index; i < arraySize; ++i){
            array[i] = array[i+1];
            if(i == arraySize - 1){
                arraySize -= 1;
                return;
            }
        }
    }
}
