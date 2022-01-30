//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  Book.h
//  ws05-part2

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <stdio.h>
#include <iostream>

namespace sdds{
class Book{
    std::string m_author;
    std::string m_title;
    std::string m_country;
    size_t m_year;
    double m_price;
    std::string m_description;
public:
    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    void newPrice(double price);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    
    //template function
    template<typename T>
    void fixSpelling(T spellChecker){
        spellChecker(m_description);
    }
    
    // trim function
    void ltrim(std::string& str) const;
};
}
#endif /* SDDS_BOOK_H */
