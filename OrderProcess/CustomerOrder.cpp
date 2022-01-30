// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"


size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(){
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;

}
CustomerOrder::CustomerOrder(const std::string& str){
    if(m_lstItem != nullptr){
        for(unsigned int i = 0u; i <m_cntItem; i++){
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        delete m_lstItem;
        m_lstItem = nullptr;
    }
        
    Utilities utilitie;
    size_t nex_po = 0;
    bool more = true;
    std::vector<std::string> tokenCollection;
    
    //store all the token into vector
    while (more) {
        std::string pushToken = utilitie.extractToken(str, nex_po, more);
        if(pushToken != ""){
            tokenCollection.push_back(pushToken);
            nex_po += tokenCollection[tokenCollection.size() - 1].length() + 1;
        }
    }
    
    //assign the first two tokens to name and product
    m_name = tokenCollection[0];
    m_product = tokenCollection[1];
    
    m_cntItem = tokenCollection.size() - 2;
    
    m_lstItem = new Item*[m_cntItem];
    //The next tokens are items
    //For each loop create a new Item and move to the m_lstItem
    for(size_t i = 0; i < m_cntItem; i++){
        m_lstItem[i] = new Item(tokenCollection[i + 2]);
    }
        
    m_widthField = utilitie.getFieldWidth();
}
CustomerOrder::CustomerOrder(const CustomerOrder&){
    throw "ERROR: Cannot make copies.";
}
CustomerOrder::CustomerOrder(CustomerOrder&& cust) noexcept{
    if(m_lstItem != nullptr && m_lstItem[0] != nullptr){
        for(unsigned int i = 0u; i <m_cntItem; i++){
            delete m_lstItem[i];
        }
        delete [] m_lstItem;
    }
    *this = std::move(cust);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cust)noexcept{
    if(this != &cust){
//        delete any item in the list if there is any
        if(m_lstItem != nullptr && m_lstItem[0] != nullptr){
            for(unsigned int i = 0u; i <m_cntItem; i++){
                delete m_lstItem[i];
            }
            delete [] m_lstItem;
        }
        
        
        //assign cust members to this obj
        m_name = cust.m_name;
        m_product = cust.m_product;
        m_cntItem = cust.m_cntItem;
        m_lstItem = cust.m_lstItem;
        
        //assign cust data members to default values;
        cust.m_name = "";
        cust.m_product = "";
        cust.m_cntItem = 0;
        
        cust.m_lstItem = nullptr;
    }
    return *this;
}
CustomerOrder::~CustomerOrder(){
    for(unsigned int i = 0u; i <m_cntItem; i++){
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }
    delete [] m_lstItem;
    m_lstItem = nullptr;
}
bool CustomerOrder::isOrderFilled() const{
    bool isAllFilled = true;
    for(unsigned int i = 0u; i <m_cntItem; i++){
        if(m_lstItem[i]->m_isFilled == false)
            isAllFilled = false;
    }
    
    return isAllFilled;
}
bool CustomerOrder::isItemFilled(const std::string& itemName) const{
    bool itemState = true;
    for(unsigned int i = 0u; i <m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == itemName){
            itemState = m_lstItem[i]->m_isFilled;
        }
    }
    return itemState;
}
void CustomerOrder::fillItem(Station& station, std::ostream& os){
    //Check if there is the station in the item list
    for(unsigned int i = 0u; i <m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == station.getItemName()){
            if(station.getQuantity() > 0){
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
            
                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }else{
                os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }
}
void CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product << std::endl;
    for(unsigned int i = 0u; i <m_cntItem; i++){
        os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] ";
        os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
        os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
    }

}
