//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Car.h
//  ws06-part1


#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <stdio.h>
#include <iostream>
#include "Vehicle.h"

namespace sdds{
class Car : public Vehicle{
    std::string m_maker{""};
    enum class Condition {brandNew, used, broken};
    Condition m_condition;
    double m_topSpeed{0};
    
public:
    Car(std::istream& str);
    std::string condition() const;
    double topSpeed() const;
    void display(std::ostream& out) const;
    void trim(std::string& str) const;
    ~Car(){};
};
}

#endif /* SDDS_CAR_H */
