#include "Data.hpp"

using namespace std;

// Pre: true.
// Post: it creates an empty date
Date::Date (){
    day=0;
    month=0;
    year=0;



}

// Pre: true.
// Post: it creates a ate witha day, month and year passed by parameter.
Date::Date(int day, int month, int year){

    this->day=day;
    this->month=month;
    this->year=year;

}

//*********************************************************
// Destructor
//*********************************************************

// Default destroyer
Date::~Date(){

}

//*********************************************************
// Consultors
//*********************************************************

// Pre: true.
// Post: it returns the day of the implicit parameter date.
int Date::getDay() const{

    return day;
}

// Pre: true.
// Post: it returns the month of the implicit parameter date.
int Date::getMonth() const{
    return month;
}

// Pre: true.
// Post: it returns the year of the implicit parameter date.
int Date::getYear() const{
    return year;
}

//pre: true
//post: returns a boolean, true if the implicit parameter date is
// previous than the date received, false in other case.
bool Date::operator>(const Date &d) const{

    bool greater=false;

    if(year<d.year){
      greater=true;
    }else if(year==d.year){
        if(month<d.month){
            greater=true;
        }else if(month==d.month and day<d.day){
            greater=true;
        }

    }
    return greater;
}
//pre: true
//post: returns a boolean, true if the implicit parameter date is
// posterior than the date received, false in other case.
bool Date::operator<(const Date &d) const{
    bool lower=false;

    if(year>d.year){
      lower=true;
    }else if(year==d.year){
        if(month>d.month){
            lower=true;
        }else if(month==d.month and day>d.day){
            lower=true;
        }
    }
    return lower;
}

// Pre: true.
// Post: it returns a boolean value, true if this and d are
// equal and false in the other case.
bool Date::operator==(const Date &d) const{
    bool valid=true;
    if(this->year!=d.year or this->month != d.month or this->day != d.day){
        valid=false;
    }
    return valid;
}

// Pre: true.
// Post: it returns a a boolean value, true if this and d are
// not equal and false in the other case.
bool Date::operator!=(const Date &d) const{
    bool valid =true;
    if(this->year==d.year and this->month == d.month and this->day == d.day){
        valid=false;
    }
    return valid;
}


//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: estan preparats al canal estàndard d'entrada tres enters */
/* Post: la data 'd' passa a tenir els enters llegits del canal
estàndard d'entrada com a dia, mes i any, respectivament */
istream& operator>>(istream &is, Date &d){
    char bar;

    is>>d.day>>bar>>d.month>>bar>>d.year;

    return is;
}

/* Pre: cert */
/* Post: s'han escrit els atributs dia, mes i any de la data 'd'
al canal estàndard de sortida */
ostream& operator<<(ostream &os, const Date &d){

    os<<d.day<<"/"<<d.month<<"/"<<d.year;
    return os;

}
