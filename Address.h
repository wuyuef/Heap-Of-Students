#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>


class Address {//address class
private:
    //variables
    std::string line1;     //line 1
    std::string line2;     //line 2
    std::string city;      //city
    std::string state;     //state
    std::string zip;       //zip code
public:
    //constructor
    Address();  //null constructor
    ~Address();
    Address(std::string,std::string,std::string,std::string,std::string);//constructor with variables
    //get functions
    std::string getLine1(); //returns first line
    std::string getLine2(); //returns second line
    std::string getCity();  //returns City
    std::string getState(); //returns State
    std::string getZip();   //returns Zip

};

#endif // ADDRESS_H
