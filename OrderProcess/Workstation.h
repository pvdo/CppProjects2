// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <stdio.h>
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station{
    std::deque <CustomerOrder> m_orders;
    Workstation* m_pNextStation = nullptr;

public:
    Workstation(const std::string& str);
    Workstation(Workstation&) = delete;
    Workstation& operator=(Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;
    void runProcess(std::ostream&);
    bool moveOrder();
    void setNextStation(Station& station);
    const Workstation* getNextStation() const;
    bool getIfCompleted(CustomerOrder& order);
    void display(std::ostream&);
    Workstation& operator+=(CustomerOrder&&);


};

#endif /* WORKSTATION_H */

