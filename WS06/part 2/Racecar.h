//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Racecar.h
//  ws06-part2

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <stdio.h>
#include <iostream>
#include "Car.h"
namespace sdds {
class Racecar:public Car{
    double m_booster{0};
public:
    Racecar(std::istream& in);
    void display(std::ostream& out) const;
    double topSpeed() const;
};
}

#endif /* SDDS_RECAR_H */
