#ifndef DATE_H
#define DATE_H

class Date {
private:
    //variable for date
    std::string month;  //month pars
    std::string day;    //day parse
    std::string year;   //year parse
    std::string date;   //what the whole line contains
public:
    //constructor
    Date(); //null constructor
    Date(std::string);//constructor with variables
    ~Date();
    //get functions
    std::string getMonth();
    std::string getDay();
    std::string getYear();
};

#endif // DATE_H