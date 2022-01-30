// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <vector>
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField = 0;
size_t Station::m_id_generator = 0;
Station::Station(const std::string& str){
    Utilities utilitie;
    size_t nex_po = 0; //position of the begging of the token
    bool more = true;
    std::vector<std::string> tokenCollection;
    while (more) {
        tokenCollection.push_back(utilitie.extractToken(str, nex_po, more));
        //The begin of the postion of the next token. Sum nex_po and the length of the last token plus the delimiter
        nex_po += tokenCollection[tokenCollection.size() - 1].length() + 1;
    }
    m_id_generator ++;
    m_id = m_id_generator;
    
    
    
    m_name = tokenCollection[0];
    m_serial = stoi(tokenCollection[1]);
    m_quantity = stoi(tokenCollection[2]);
    m_description = tokenCollection[3];
   
    m_widthField = utilitie.getFieldWidth();
}


const std::string& Station::getItemName() const{
    return m_name;
}
unsigned int Station::getNextSerialNumber(){
    return m_serial++;
}
unsigned int Station::getQuantity() const{
    return m_quantity;
}
void Station::updateQuantity(){
    if(m_quantity > 0)
        m_quantity --;
}
void Station::display(std::ostream& os, bool full) const{
    os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]"
    << " Item: " << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name
    << " [" << std::setw(6) << std::setfill('0') << std::right << m_serial << "]";
    
    if(full){
        os << " Quantity: " << std::left << std::setfill(' ') << std::setw(m_widthField) << m_quantity
        << " Description: " << m_description;
    }
    os << std::endl;
}
