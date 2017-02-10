#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;

//constructor
Date::Date(){       //null constructor
    /*day = "27";
    month = "9";
    year = "1994";*/
}

Date::Date(string date){    //constructor with varibales

    //cout << "date: " << date << endl;
    stringstream date_hold;                  //counter
    date_hold << date;      //sends string to the string stream

    getline(date_hold, date, '/') ; //parses line between '/'
    Date::month = date;

    getline(date_hold, date, '/');  //parses line between '/'
    Date::day = date;

    getline(date_hold, date, '/');  //parses line between '/'
    Date::year = date;

}

Date::~Date(){
}

//get fucntions
string Date::getDay(){  //returns day
    return day;
}

string Date::getMonth(){    //returns month
    return month;
}

string Date::getYear(){     //returns year
    return year;
}
