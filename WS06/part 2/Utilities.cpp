//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Utilities.cpp
//  ws06-part2

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds{

Vehicle* createInstance(std::istream& in){
    Vehicle* newCar;
    std::string strIn;
    std::getline(in, strIn);
    strIn.erase(0, strIn.find_first_not_of(" "));
    
    if(strIn[0] == 'c' || strIn[0] == 'C'){
        std::stringstream ss(strIn);
        newCar = new Car(ss);
    }else if(strIn[0] == 'r' || strIn[0] == 'R'){
        std::stringstream ss(strIn);
        newCar = new Racecar(ss);
    }else if(strIn[0] != 'c' && strIn[0] != 'C'&& strIn[0] != 'r' && strIn[0] != 'R' && strIn[0] != '\0'){
        throw strIn[0];
    }else{
        newCar = nullptr;
    }
    
    return newCar;
    
}
}
