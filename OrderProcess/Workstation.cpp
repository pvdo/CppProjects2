// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//

#include "Workstation.h"
#include <deque>

Workstation::Workstation(const std::string& str) : Station(str){

}

void Workstation::runProcess(std::ostream& os){
    if(!m_orders.empty()){
        m_orders.front().fillItem(*this, os);
    }
}
bool Workstation::moveOrder(){
    bool moved = false;
    if(!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation){
        *m_pNextStation += std::move(m_orders.front());
        m_orders.pop_front();
        moved = true;
    }
    return moved;
}
void Workstation::setNextStation(Station& station){
    // make the refenrence of station as a Workshop pointer and store in the m_pNextStation pointer
    m_pNextStation = (Workstation *) &station;
}
const Workstation* Workstation::getNextStation() const{
    return m_pNextStation;
}
bool Workstation::getIfCompleted(CustomerOrder& order){
    bool completed = false;
    if(!m_orders.empty()){
        if(!m_orders.empty() && m_orders.front().isOrderFilled()){
            order = std::move(m_orders.front());
            m_orders.pop_front();

            completed = true;
        }
    }
    return completed;
}
void Workstation::display(std::ostream& os){
    if(m_pNextStation != nullptr){
        os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
    }else{
        os << getItemName() << " --> END OF LINE" << std::endl;
        
    }
}
Workstation& Workstation::operator+=(CustomerOrder&& cust){
    m_orders.push_back(std::move(cust));
    return *this;
}
