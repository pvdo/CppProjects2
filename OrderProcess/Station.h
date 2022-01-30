// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <stdio.h>
#include <iostream>

class Station{
    size_t m_id{0};
    std::string m_name;
    std::string m_description;
    unsigned int m_serial{0};
    unsigned int m_quantity{0};
    static size_t m_widthField;
    static size_t m_id_generator;
public:
    Station(const std::string& str);
    const std::string& getItemName() const;
    unsigned int getNextSerialNumber();
    unsigned int getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
    
    
    
};
#endif /* SDDS_STATION_H */
