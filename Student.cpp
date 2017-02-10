#include "Student.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

//constructor
Student::Student(){         //null constructor
    //cout << "null check" << endl;
    /*first_name = "Caleb";
    last_name = "Elliott";
    Address* stu_AddressTemp = new Address();   //creates a null address
    stu_Address = *stu_AddressTemp;
    Date* stu_BirthTemp = new Date();           //creates a null date
    stu_Birth = *stu_BirthTemp;
    Date* stu_GradTemp = new Date();            //creats a null date
    stu_Grad = *stu_GradTemp;
    credits = "120";
    GPA = "4.00";*/
}

Student::Student(string stuInfo){//constructs object student with given data
    stringstream ss;
    string str;
    ss << stuInfo;

    getline(ss, str, ',');
    Student::last_name = str;  //assigns first name


    getline(ss, str, ',');
    Student::first_name = str;   //assigns last name

    getline(ss, str, ',');
    Student::line1 = str;       //assigns street1

    getline(ss, str, ',');
    Student::line2 = str;       //assigns stree2

    getline(ss, str, ',');
    Student::city = str;        //assigns city

    getline(ss, str, ',');
    Student::state = str;       //assigns state

    getline(ss, str, ',');
    Student::zip = str;         //assigns zip

    getline(ss, str, ',');
    Student::DOB = str;         //assigns DOB

    getline(ss, str, ',');
    Student::DOG = str;         //assigns DOG

    getline(ss, str, ',');
    Student::GPA = str;         //assigns GPA

    getline(ss, str, ',');
    Student::credits = str;     //assogns credits

    Address* stu_AddressTemp = new Address(line1,line2, city, state, zip); //creates address object with given info and stores int temp
    stu_Address = *stu_AddressTemp;                                         //derefernces temp and stores in student variables
    delete stu_AddressTemp;

    Date* stu_BirthTemp = new Date(DOB);    //creates date object with given info and stores in temp
    stu_Birth = *stu_BirthTemp;             //dereferences temp and stores in variable
    delete stu_BirthTemp;

    Date* stu_GradTemp = new Date(DOG);     //creates date object with given info and stores in temp
    stu_Grad = *stu_GradTemp;               //dereferences temp and stores in variable
    delete stu_GradTemp;

}

Student::~Student() {

}

string Student::getFName(){     //returns first name
    return first_name;
}

string Student::getLName(){     //returns last name
    return last_name;
}

string Student::getCredits(){   //returns credits
    return credits;
}

string Student::getGPA(){       //returns GPA
    return GPA;
}



string Student::getSimpleReport(){      //returns a simple report

    string simp_report = first_name + " " + last_name;  //just first an last name
    return simp_report;

}

string Student::getReport(){    //returns the whole report
    string report = first_name + " " + last_name + " " +  stu_Address.getLine1() + " " +  stu_Address.getLine2()+ " " +  stu_Address.getCity()+ " " +  stu_Address.getState()+ " " +  stu_Address.getZip()+ " Birthday: " + stu_Birth.getMonth() + "/" + stu_Birth.getDay() + "/" + stu_Birth.getYear() + " Anticipated Grad: " + stu_Grad.getMonth() + "/" + stu_Grad.getDay() + "/" + stu_Grad.getYear() + "/" + "GPA: " + GPA + " " "Credits: " + credits;
    return report;  // first name, last name, address, birth, grad, GPA, and credits
}

string Student::getEuropean(){    //returns the whole report
    string report = first_name + " " + last_name + " " +  stu_Address.getLine1() + " " +  stu_Address.getLine2()+ " " +  stu_Address.getCity()+ " " +  stu_Address.getState()+ " " +  stu_Address.getZip()+ " Birthday: " + stu_Birth.getDay() + "/" + stu_Birth.getMonth() + "/" + stu_Birth.getYear() + " Anticipated Grad: " + stu_Grad.getDay() + "/" + stu_Grad.getMonth() + "/" + stu_Grad.getYear() + "/" + "GPA: " + GPA + " " "Credits: " + credits;
    return report;  // first name, last name, address, birth, grad, GPA, and credits
}

