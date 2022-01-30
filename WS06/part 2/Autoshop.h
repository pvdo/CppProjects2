//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Autoshop.h
//  ws06-part2


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
class Autoshop{
    std::vector<Vehicle*> m_vehicles;
    
public:
    Autoshop& operator +=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
    ~Autoshop();
    
    template<typename T>
    void select(T test, std::list<const Vehicle*>& vehicles){
        for(size_t i = 0; i < m_vehicles.size(); i++){
            if(test(m_vehicles[i])){
                vehicles.insert(vehicles.end(), m_vehicles[i]);
            }
        }
    }
};
}
#endif /* SDDS_AUTOSHOP_H */
