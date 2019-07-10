#include "Distance.h"

Distance::Distance(){
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in){
    feet = 0;
    inches = in;
    init();
}

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    double y = 0.0;
    y = (feet * 12) + inches;
    
    return y;
}

double Distance::distanceInFeet() const{
    double y = 0.0;
    y = feet + (inches / 12);
    
    return y;
}

double Distance::distanceInMeters() const{
    double y = 0.0;
    y = (feet * 12) + inches;
    y = y * .0254;
    
    return y;
}

const Distance Distance::operator+(const Distance& rhs) const{
    Distance pValue;
    
    pValue.feet = feet + rhs.feet;
    pValue.inches = inches + rhs.inches;
    
    Distance pValue2(pValue.feet, pValue.inches);
    
    return pValue2;
}

const Distance Distance::operator-(const Distance& rhs) const{
    Distance mValue;
    
    if(feet >= rhs.feet){
        mValue.feet = feet - rhs.feet;
        if(inches >= rhs.inches){
            mValue.inches = inches - rhs.inches;
        }
        else{
            if(feet == 0){
                mValue.feet = rhs.feet;
                mValue.inches = rhs.inches - inches;
            }
            else{
                mValue.feet = feet - rhs.feet - 1;
                if(mValue.feet < 0){
                    mValue.feet = feet - rhs.feet;
                    mValue.inches = rhs.inches - inches;
                }
                else if (mValue.feet == 0){
                    mValue.feet = rhs.feet;
                    mValue.inches = rhs.inches - inches;
                }
                else{
                    mValue.feet = feet - rhs.feet - 1;
                    mValue.inches = 12 - (rhs.inches - inches);
                }
            }
        }
    }
    else{
        if(rhs.inches > inches){
            mValue.feet = rhs.feet - feet - 1;
            if(mValue.feet == 0){
                mValue.inches = 12 - (rhs.inches - inches);
            }
            else{
                mValue.feet = rhs.feet - feet;
                mValue.inches = rhs.inches - inches;
            }
        }
        else{
            mValue.feet = rhs.feet - feet - 1;
            mValue.inches = 12 - (inches - rhs.inches);
        }
    }
    
    Distance mValue2(mValue.feet, mValue.inches);
    
    return mValue2;
}

ostream & operator<<(ostream& out, const Distance& rhs){
    out << rhs.feet << "' " << rhs.inches << "\"";
    
    return out;
}

void Distance::init(){
    int value = 0;
    
    if(feet < 0)
        feet = 0;
    if(inches < 0)
        inches = inches * -1;
    if(inches >= 12){
        value = inches / 12;
        inches = inches - ((13 * value) - value);
        feet = feet + value;
    }
}
