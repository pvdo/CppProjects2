//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  Movie.cpp
//  ws05-part2

#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds{
Movie::Movie(){
    
}
const std::string& Movie::title() const{
    return m_title;
}

void Movie::trim(std::string& str) const {
    size_t i = 0u;
    //begin
    for (i = 0u; i < str.length() && str[i] == ' '; ++i);
    str = str.substr(i);
    //middle
    
    //end
    for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
    str = str.substr(0, i);
}

Movie::Movie(const std::string& strMovie){
    std::string temp = strMovie;
        // -------Title
        //erase first whitespaces
        temp.erase(0, temp.find_first_not_of(" "));
        // string size
        std::string tempTitle = temp.substr(0, temp.find(","));
        //erase end whitespaces
        trim(tempTitle);
        m_title = tempTitle;
        //erase Title
        temp.erase(0, temp.find(",") + 1);
       
        // -----YEAR
        temp.erase(0, temp.find_first_not_of(" "));
        m_year = std::stoi(temp.substr(0, temp.find(",")));
        temp.erase(0, temp.find(",") + 1);
       
        // -----DESCRIPTION
        temp.erase(0, temp.find_first_not_of(" "));
        m_description = temp.substr(0, temp.find('\n'));
}
 
std::ostream& operator<<(std::ostream& os, const Movie& movie){
    os << std::setw(40) << movie.m_title << " | ";
    os << std::setw(4) << movie.m_year << " | ";
    os << std::setw(22) << movie.m_description << std::endl;
    
    return os;
}
}
