// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(){

}
LineManager::LineManager(const std::string &strFile, std::vector<Workstation*> &wStation, std::vector<CustomerOrder> &cust){
    Utilities utilitie;
    size_t nex_po = 0;
    bool more = true;
    //transform string to fstream to be able to reach line by line
    std::fstream f(strFile);
    //Each line has two tokens
    std::string oneLine;
    //ws1 = first token, ws2 = second token
    std::string ws1, ws2;
    while (f) {
        //read one line
        getline(f, oneLine);
            nex_po = 0;
            //first station
            ws1 = utilitie.extractToken(oneLine, nex_po, more);
            //the position of the beginning of the second token; size of the firt token + delimiter;
            nex_po += ws1.size()+1;
            for(size_t i = 0u; i < wStation.size(); i++){
                //if the token ws1 has the same value of the item name of the station parameter in the index "i"...
                if(ws1 == wStation[i]->getItemName()){
                    //and if there is more token besides the first token
                    if(more){
                    //get the second station to the ws2 token
                        ws2 = utilitie.extractToken(oneLine, nex_po, more);
                        //run thorght the elements of wStation parameters...
                        for(size_t j = 0u; j < wStation.size(); j++){
                            //found the same value of ws2 and the item name of the station parameter in the index "j"...
                            if(ws2 == wStation[j]->getItemName()){
                                //that way set the next station of the workstation "i" as the workstation "j"
                                wStation[i]->setNextStation(*wStation[j]);
                                
                            }
                        }
                    }
                    //store the workstation in the linkedOrder to keep track of the right order of the station was linked.
                    linkedOrder.push_back(wStation[i]);
                }
                

            }
        

    }
    //copy all the values of the parameters to the data member assemblyLine
    assemblyLine = wStation;
    //make the value of the number of customer as the size of the vector CustomerOrder parameter
    m_cntCustomerOrder = cust.size();
    //move all the elements of the cust to the toBeFilled data member
    for(size_t i = 0; i < m_cntCustomerOrder; i++){
        toBeFilled.push_back(std::move(cust[i]));
    }

}
bool LineManager::run(std::ostream& os){
    bool filled = false;
    //make count static in order to avoid count restart
    static int count = 0;
    
    //each time this function is call count + 1
    os << "Line Manager Iteration: " << ++count << std::endl;

    if(!toBeFilled.empty()){
        
        //dereference the linkedOrder and move the value of the first element of toBeFilled to the linkedOrder using the += overloaded operation
        *linkedOrder.front() += std::move(toBeFilled.front());
        //eliminate the index of the value passed
        toBeFilled.pop_front();
    }
    for(size_t i = 0; i < assemblyLine.size(); i++){
        //run all the workstation to the runProcess to fill the item of each order
        assemblyLine[i]->runProcess(os);
    }
    // create a temp CustomerOrder to hold the completed orders that wasnt pushed to the completed data member
    CustomerOrder temp;
    for(size_t i = 0; i < assemblyLine.size(); i++){
        assemblyLine[i]->moveOrder();
        //Check if the orders of the specific Workstation was completed
        if(assemblyLine[i]->getIfCompleted(temp)){
            //if was, push it to completed
            completed.push_back(std::move(temp));
        }
    }
    //Check if all customers has been filled
    if(completed.size() == m_cntCustomerOrder){
        filled = true;
    }
    return filled;
}
void LineManager::displayCompletedOrders(std::ostream& os) const{
    for(size_t i = 0; i < completed.size(); i++){
        completed[i].display(os);
    }
}
void LineManager::displayStations() const{
    for(size_t i = 0; i < assemblyLine.size(); i++){
        assemblyLine[i]->display(std::cout);
    }
}
void LineManager::displayStationsSorted() const{
    for(size_t i = 0; i < assemblyLine.size(); i++){
        linkedOrder[i]->display(std::cout);
    }
}

