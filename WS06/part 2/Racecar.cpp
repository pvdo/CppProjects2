//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Racecar.h
//  ws06-part2

#include <iostream>
#include "Racecar.h"

namespace sdds{
Racecar::Racecar(std::istream& in) : Car(in){
    //reset in stream after using it in the car constructor
    in.clear();
    in.seekg(0, in.beg);
    std::string temp;
    getline(in, temp);

    std::string booster = temp.substr(temp.find_last_of(',') + 1);
    trim(booster);
    m_booster = std::stod(booster);
}
void Racecar::display(std::ostream& out) const{
    Car::display(out);
    out << "*";
}
double Racecar::topSpeed() const{
    double top = Car::topSpeed() + (Car::topSpeed() * m_booster);
    
    return top;
}
}
