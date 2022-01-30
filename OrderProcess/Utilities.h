//Workshop 1 - TASK 1
//Course:<subject type> - Semester
//Last Name: Do Carmo Saraiva Teixeira
//First Name: Pedro Vitor
//ID: 100036193
//Section: NDD
//This assignment represents my own work in accordance with Seneca Academic Policy. Signature
//Date: September 26, 2020

#ifndef UTILITES_H
#define UTILITES_H

#include <stdio.h>
#include <iostream>


class Utilities{
    static size_t m_widthField;
    static char m_delimiter;
public:
    void setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter){
        m_delimiter = newDelimiter;
    }
    static char getDelimiter(){
        return m_delimiter;
    }
    
};
#endif /* UTILITES_H */
