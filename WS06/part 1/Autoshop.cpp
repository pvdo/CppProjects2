//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Autoshop.cpp
//  ws06-part1

#include <vector>
#include <iostream>
#include <iomanip>
#include "Autoshop.h"

namespace sdds{

Autoshop& Autoshop::operator +=(Vehicle* theVehicle){
    m_vehicles.push_back(theVehicle);
    return *this;
}
Autoshop::~Autoshop(){
    for(size_t i = 0; i < m_vehicles.size(); i++){
        delete m_vehicles [i];
    }
}
void Autoshop::display(std::ostream& out) const{
    out << "--------------------------------"<< std::endl;
    out << "| " << std::setw(28) << std::left << "Cars in the autoshop!" << " |" << std::endl;
    out << "--------------------------------"<< std::endl;
    for(size_t i = 0; i < m_vehicles.size(); i++){
        m_vehicles[i]->display(out);
    }
    out << "--------------------------------"<< std::endl;
}
}
