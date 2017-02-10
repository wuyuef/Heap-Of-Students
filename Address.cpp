#include "Address.h"    //includes Address header

using namespace std;

//constructors
Address::Address(){                 //null constructor
    line1 = "811 N California St";
    line2 = "";
    city = "Indianapolis";
    state = "IN";
    zip = "46202";
}

Address::Address(string newLine1, string newLine2, string newCity, string newState, string newZip){ //constructor
    line1 = newLine1;       //creates object with line 1 of address
    line2 = newLine2;       //creates object with line 2 of address
    city = newCity;         //creates omakbject with city of address
    state = newState;       //creates object with State of address
    zip = newZip;           ////creates object with zip  of address
}

Address::~Address() {

}


//get functions
string Address::getLine1(){     //returns first line of address
    return line1;
}

string Address::getLine2(){     //returns second line of address
    return line2;
}

string Address::getCity(){      //returns City of address
    return city;
}

string Address::getState(){     //returns State of address
    return state;
}

string Address::getZip(){       //returns Zip of address
    return zip;
}