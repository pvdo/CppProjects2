//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Autoshop.h
//  ws06-part1


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Vehicle.h"

namespace sdds {
class Autoshop{
    std::vector<Vehicle*> m_vehicles;
    
public:
    Autoshop& operator +=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
    ~Autoshop();
};
}
#endif /* SDDS_AUTOSHOP_H */
