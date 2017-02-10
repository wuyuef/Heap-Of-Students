#include <iostream> // input output stream
#include <fstream>  // for input and output files
#include <string>   // for strng fuctions
#include <sstream>  // defines the stringstream
#include <cstdlib>  // defines atoi

#include "Address.h"    //Address header
#include "Date.h"       //Date header
#include "Student.h"    //Student header

using namespace std;    //convenience

void print(Student stud){               //prints the full report
    string print = stud.getReport();    //calls students report function and assigns the return to print
    cout << print << endl;              //prints
}   //end print

void simple(Student stud){                  //prints just first and last name
    string print = stud.getSimpleReport();  // callls the students simple report functions and return to print
    cout << print << endl;                  //prints
}   // end simple

void european(Student stud){                //prints the full report with european dates
    string print = stud.getEuropean();      //calls the European report function and assigns the return to prin
    cout << print << endl;                  //prints
}   //end european

int main(){
    cout << "\n\nthis program makes a student object and allows a simple and full print, gives the option for a eurropean date system, you can choose a person by their number or their name, \n" << endl;
    char cont = true;               //while loop variable
    ifstream inFile;                //if stream
    inFile.open("students.dat");//reads in student data
    Student* stud = new Student[51];//stud is an array of 50 students. has to be fifty one because eof adds one
    Student student_holder;         //holds the info before transfering to stud
    string stu_info;                //temporarily holds part of a student info before assigning to string s
    int print_check;                //what do you want to print
    int i;                          //counter
    //getline(inFile, stu_info);      //for getting rid of the header line

    if(inFile.is_open()){                               // checks if the file opened
        for(i = 0; i < 51; i++){                 //for loops. while not at end of file adds to i
            getline(inFile, stu_info);                  //gets a line from the fileStudent* stud_hold = new Student(stu_info); //creates a Student with parsed info and assigns it to stu_hold
            Student* stud_hold = new Student(stu_info); //creates a Student with parsed info and assigns it to stu_hold
            student_holder = *stud_hold;                //dereferences and assigns to a hold
            delete stud_hold;
            stud[i] = student_holder;                   //assigns hold to array
        }
        //inFile.close();                                 // close infile
    }
    else {                                              // if it could open the file
        cout << "Didn't open" << endl;
    }


    while(cont){ //continues until user decides to quit
        cout << "What would you like to do:\n 1: full report \n 2: simple report\n 3: European dates full report\n 4: choose a person by their ID number\n 5: sort the list\n 6: choose a person by their last name\n 7: nothing" << endl;//cout
        cin >> print_check; //reads in the print choice

        if (print_check == 1){              //full report option
            cout << "Student Report: \n" << endl;;
            for(i = 0; i < 51; i ++){       // each instance of student
                print(stud[i]);             //calls function to print full report
            }
        }
        else if (print_check == 2){         //simple report option
            cout << "Simple Student Report: \n" << endl;
            for(i = 0; i < 51; i++){        // each instance of student
                simple(stud[i]);            //calls fucniton to print a simple report
            }
        }

        else if (print_check == 3){         //european dates option
            cout << "European Style Report: \n"<< endl;
            for(i = 0; i < 51; i++){        // each instance of student
                european(stud[i]);          //calls fucniton to print the full report with European dates
            }
        }
        else if (print_check == 4){         //choose someone's report by their id number
            int who;                        //hold the id number
            int sys;                        //variable for date system
            cout << "who's file would you like to look at. please enter their ID number\n" << endl;
            cin >> who;                     //reads in the id number
            if (who > 51){                  // checks if the id number is valid
                cout << "sorry that is an invalid student ID" << endl;
            }
            else{
                cout << "would you like the European or American style date system? [1,2]" << endl;
                cin >> sys;                     //reads in the date system choice
                if (sys == 1){
                    european(stud[who]);        //European
                }
                else if (sys == 2){
                    print(stud[who]);           //American Standard
                }
                else{
                    cout << "sorry that was not a correct response" << endl;    //didnt enter a correct date choice
                }
            }
        }
        else if (print_check == 5){ //sorts the student's alphabetically
            int i = 0;      //counter
            int j = 0;      //counter
            Student temp;               // holding variable
            int sorter;

            cout << "would you like to sort by:\n 1: first name\n 2: last name\n 3: gpa\n 4: credits\n" << endl;
            cin >> sorter;

            if (sorter == 1){   //first name sort
                for(i = 1; i < 50; i++){     //first for loop for bubble sort
                    for (j=1; j < 50; j++){ //second for loop for bubble sort
                        if (stud[j].getFName() > stud[j+1].getFName()){      //if out of order
                            temp = stud[j];             // swap elements
                            stud[j] = stud[j+1];
                            stud[j+1] = temp;
                        }//end iff
                    }// end for
                }// end for
            }// end if

            if (sorter == 2){   //last name sort
                for(i = 1; i < 50; i++){     //first for loop for bubble sort
                    for (j=1; j < 50; j++){ //second for loop for bubble sort
                        if (stud[j].getLName() > stud[j+1].getLName()){      //if out of order
                            temp = stud[j];             // swap elements
                            stud[j] = stud[j+1];
                            stud[j+1] = temp;
                        }//end iff
                    }// end for
                }// end for
            }// end if

            if (sorter == 3){   //gpa sort
                for(i = 1; i < 50; i++){     //first for loop for bubble sort
                    for (j=1; j < 50; j++){ //second for loop for bubble sort
                        if (stud[j].getGPA() < stud[j+1].getGPA()){      //if out of order
                            temp = stud[j];             // swap elements
                            stud[j] = stud[j+1];
                            stud[j+1] = temp;
                        }//end iff
                    }// end for
                }// end for
            }// end if

            if (sorter == 4){   //credits sort
                for(i = 1; i < 50; i++){     //first for loop for bubble sort
                    for (j=1; j < 50; j++){ //second for loop for bubble sort
                        if (stud[j].getCredits() < stud[j+1].getCredits()){      //if out of order
                            temp = stud[j];             // swap elements
                            stud[j] = stud[j+1];
                            stud[j+1] = temp;
                        }//end iff
                    }// end for
                }// end for
            }// end if


        }

        else if (print_check == 6){     //choosing a person by their last name
            string who;                 //name variable
            int person = 0;             //ID number variable
            bool check = false;         //check
            int sys;                    //system type
            cout << "Who's file would you like to look at. Please enter their last name.\nBe sure to only capitalize the first letter!" << endl;
            cin >> who;                 //reads in the last name

            for(i = 0; i < 51; i ++){   //for loops checks every person in the data base
                if (who.compare(stud[i].getLName()) == 0){  //if there is a match
                    person = i;         //assins the ID number
                    check = true;       //cchanges check to true if there is a match
                    cout << "one moment please..." << endl;
                }
            }
            if (check == false){          //if there wasnt a match
                cout << "sorry that person is not in our database" << endl;
            }
            else{                           //if there was a match
                cout << "would you like the European or American style date system? [1,2]" << endl;
                cin >> sys;                 //reads in data system
                if (sys == 1){
                    european(stud[person]); //European
                }
                else if (sys == 2){
                    print(stud[person]);    //American standard
                }
                else{
                    cout << "sorry that was not a correct response" << endl;
                }
            }
        }
        else{       //user ends program
            cout << "ta ta for now" << endl;
            cont = false;
        }
        /*cout << "press enter to continue\n" << endl;
        cin.ignore();
        cin.ignore();*/
    }

    inFile.close();     //infile close
    delete[] stud;      //delete array

    return 0;
}   //ends main


