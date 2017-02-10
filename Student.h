#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"
#include "Date.h"
#include <string>


class Student{
private:
    //variables
    std::string first_name; //string first name
    std::string last_name;  //last name
    Address stu_Address;    //address object
    Date stu_Birth;         //date object
    Date stu_Grad;          //date object
    std::string GPA;        //gpa
    std::string credits;    //credits
    std::string DOB;
    std::string DOG;
    std::string line1;
    std::string line2;
    std::string city;
    std::string state;
    std::string zip;
public:
    //constructor
    Student();  //null constructor
    Student(std::string);//constructor with variables
    ~Student();
    //get functions
    std::string getFName();         //returns the First name
    std::string getLName();         //returns the Last name
    std::string getGPA();           //returns the GPA
    std::string getCredits();       //returns the credits
    std::string getSimpleReport();  // returns first and last name
    std::string getReport();        //returns entire Report
    std::string getEuropean();	//returns reprot with European dates

};

#endif // STUDENT_H