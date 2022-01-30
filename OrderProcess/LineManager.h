// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <stdio.h>
#include <vector>
#include <deque>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager{
    std::vector<Workstation*> assemblyLine;
    //linkedOrder keep track of the order of the station was linked.
    std::vector<Workstation*> linkedOrder;
    std::deque<CustomerOrder> toBeFilled;
    std::deque<CustomerOrder> completed;
    unsigned int m_cntCustomerOrder;
public:
    LineManager();
    LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream& os);
    void displayCompletedOrders(std::ostream& os) const;
    void displayStations() const;
    void displayStationsSorted() const;

};

#endif /* LINEMANAGER_H */


