//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/24

//  Book.cpp
//  ws05-part1

#include "Book.h"
#include <iostream>
#include <iomanip>

namespace sdds {
Book::Book(){
    m_author = "";
    m_title = "";
    m_country = "";
    m_year = 0;
    m_price = 0;
    m_description = "";
}

Book::Book(const std::string& strBook){
    std::string temp = strBook;
    // -------AUTHOR
    //erase first whitespaces
    temp.erase(0, temp.find_first_not_of(" "));
    // string size
    std::string tempAuthor = temp.substr(0, temp.find(","));
    //erase end whitespaces
    ltrim(tempAuthor);
    m_author = tempAuthor;
    //erase Author
    temp.erase(0, temp.find(",") + 1);
    

    
    // ------TITLE
    //erase first whitespaces
    temp.erase(0, temp.find_first_not_of(" "));
    //string size
    std::string tempTitle = temp.substr(0, temp.find(","));
    //erase end whitespaces
    ltrim(tempTitle);
    m_title = tempTitle;
    //erase title
    temp.erase(0, temp.find(",") + 1);
    
    // -----COUNTRY
    //erase first whitespaces
    temp.erase(0, temp.find_first_not_of(" "));
    std::string tempCountry = temp.substr(0, temp.find(","));
    ltrim(tempCountry);
    m_country = tempCountry;
    temp.erase(0, temp.find(",") + 1);
    
    // -----PRICE
    temp.erase(0, temp.find_first_not_of(" "));
    m_price = std::stod(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",") + 1);
    
    // -----YEAR
    temp.erase(0, temp.find_first_not_of(" "));
    m_year = std::stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",") + 1);
    
    // -----DESCRIPTION
    temp.erase(0, temp.find_first_not_of(" "));
    m_description = temp.substr(0, temp.find('\n'));
    
    
    
}


void Book::ltrim(std::string& str) const {
    size_t i = 0u;
    
    for (i = 0u; i < str.length() && str[i] == ' '; ++i);
    str = str.substr(i);
    for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
    str = str.substr(0, i);
}
const std::string& Book::title() const{
    return m_title;
}

const std::string& Book::country() const{
    return m_country;
}

const size_t& Book::year() const{
    return m_year;
}

double& Book::price(){
    return m_price;
}

void Book::newPrice(double price){
    m_price = price;
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << std::setw(20) << book.m_author << " | ";
    os << std::setw(22) << book.m_title << " | ";
    os << std::setw(5) << book.m_country << " | ";
    os << std::setw(4) << book.m_year << " | ";
    os << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
    os << std::setw(22) << book.m_description << std::endl;
    
    return os;
}
}
