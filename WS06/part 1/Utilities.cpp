//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Utilities.cpp
//  ws06-part1

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds{
Vehicle* createInstance(std::istream& in){
    std::string strIn;
    std::getline(in, strIn);
    strIn.erase(0, strIn.find_first_not_of(" "));
    std::stringstream ss(strIn);
    return strIn[0] == 'c' || strIn[0] == 'C'? new Car(ss) : nullptr;
    
}
}
//    if(strIn[0] == 'c' || strIn[0] == 'C'){
//        std::stringstream ss(strIn);
//         newCar = new Car(ss);
//    }else{
//        newCar = nullptr;
//    }
//
//    return newCar;
