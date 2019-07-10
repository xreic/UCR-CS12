#include <iostream>

using namespace std;

class Date{
 private:
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;
    
 public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const string &mn, unsigned d, unsigned y);
    void printNumeric() const;
    void printAlpha() const;
    
 private:
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth(unsigned m, unsigned y) const;
    string name(unsigned m) const;
    unsigned number(const string &mn) const;
};

Date getDate();

int main(){
    Date testDate;
    testDate = getDate();
    cout << endl;
    cout << "Numeric: ";
    testDate.printNumeric();
    cout << endl;
    cout << "Alpha:   ";
    testDate.printAlpha();
    cout << endl;

    return 0;
}

Date getDate(){
    int choice;
    unsigned monthNumber, day, year;
    string monthName;

    cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
		<< "1 - Month Number" << endl
		<< "2 - Month Name" << endl
		<< "3 - default" << endl;
    cin >> choice;
    cout << endl;

    if (choice == 1){
		cout << "month number? ";
		cin >> monthNumber;
		cout << endl;
		cout << "day? ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthNumber, day, year);
    } 
    else if (choice == 2){
		cout << "month name? ";
		cin >> monthName;
		cout << endl;
		cout << "day? ";
		cin >> day;
		cout << endl;
		cout << "year? ";
		cin >> year;
		cout << endl;
		return Date(monthName, day, year);
    }
    else
		return Date();
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
	if(m == 1)
		return 31;
	else if(m == 2){
		if(isLeap(y))
			return 29;
		return 28;
	}
	else if(m == 3)
		return 31;
	else if(m == 4)
		return 30;
	else if(m == 5)
		return 31;
	else if(m == 6)
		return 30;
	else if(m == 7)
		return 31;
	else if(m == 8)
		return 31;
	else if(m == 9)
		return 30;
	else if(m == 10)
		return 31;
	else if(m == 11)
		return 30;
	else
		return 31;
}

bool Date::isLeap(unsigned y) const{
	if(y % 400 == 0 || y % 100 != 0){
        if(y % 4 == 0)
            return true;
        else
            return false;
	}
	return false;
}

string Date::name(unsigned m) const{
	if(m <= 1)
		return "January";
	else if(m == 2)
		return "February";
	else if(m == 3)
		return "March";
	else if(m == 4)
		return "April";
	else if(m == 5)
		return "May";
	else if(m == 6)
		return "June";
	else if(m == 7)
		return "July";
	else if(m == 8)
		return "August";
	else if(m == 9)
		return "September";
	else if(m == 10)
		return "October";
	else if(m == 11)
		return "November";
	else
		return "December";
		
}

unsigned Date::number(const string &mn) const{
	if(mn == "January" || mn == "january")
		return 1;
	else if(mn == "February" || mn == "february")
		return 2;
	else if(mn == "March" || mn == "march")
		return 3;
	else if(mn == "April" || mn == "april")
		return 4;
	else if(mn == "May" || mn == "may")
		return 5;
	else if(mn == "June" || mn == "june")
		return 6;
	else if(mn == "July" || mn == "july")
		return 7;
	else if(mn == "August" || mn == "august")
		return 8;
	else if(mn == "September" || mn == "september")
		return 9;
	else if(mn == "October" || mn == "october")
		return 10;
	else if(mn == "November" || mn == "november")
		return 11;
	else if(mn == "December" || mn == "december")
		return 12;
	else
		return 13;
}

Date::Date(){
	year = 2000;
	month = 1;
	monthName = "January";
	day = 1;
}

Date::Date(unsigned m, unsigned d, unsigned y){
	year = y;
	unsigned int value = 0;
	month = m;
	monthName = name(m);
	
	if(m > 0 && m < 13){
		value =	daysPerMonth(m, y);
	}
	else if(m < 1){
		month = 1;
		monthName = "January";
	}
	else if (m > 12){
		month = 12;
		monthName = "December";
	}
		
		
	if(d > 0 && d <= value)
		day = d;
	else if (d < 1){
		day = 1;
		cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
	}
	else if (d > value){
		value =	daysPerMonth(m, y);
		day = value;
		cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
	}
}

Date::Date(const string &mn, unsigned d, unsigned y){
	year = y;
	unsigned int valueM = number(mn);
	unsigned int value = daysPerMonth(valueM, y);
	
	
	if(valueM != 13){
		month = valueM;
		monthName = name(valueM);
	}
	if(valueM == 13){
		year = 2000;
		month = 1;
		monthName = "January";
		day = 1;
		cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
	}
	
	if((d > 0 && d <= value) && valueM < 13)
		day = d;
	else if (d < 1 && valueM < 13){
		day = 1;
		cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
	}
	else if (d > value && valueM < 13){
		day = value;
		cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
	}
}

void Date::printNumeric() const{
	cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const{
	cout << monthName << " " << day << ", " << year;
}
