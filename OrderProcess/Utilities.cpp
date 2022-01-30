// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Seneca Student ID: 100036193
// Seneca email: pvdo-carmo-saraiva-t@myseneca.ca
// Date of completion: 
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"

char Utilities::m_delimiter = ' ';
size_t Utilities::m_widthField = 1;
void Utilities::setFieldWidth(size_t newWidth){
    m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    std::string token;

    if (next_pos < str.size()) {
        more = true;
        //find position of the delimiter
        auto delimiter = str.substr(next_pos).find(m_delimiter);
        token = str.substr(next_pos, delimiter);

        if (token.size() == 0) {
            throw "Invalid token!";
        }
        //grab last item
        std::string lastItem = str.substr(str.find_last_of(m_delimiter) + 1, str.size());
        //if the token is last item dont add the lenght of it in the fieldWidrh
        if (m_widthField < token.length() && token != lastItem) {
            setFieldWidth(token.length());
        }
    }
    else {
        more = false;
    }
    
    return token;
}

