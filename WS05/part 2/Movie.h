//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  Movie.h
//  ws05-part2

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <stdio.h>
namespace sdds{
class Movie{
    std::string m_title{""};
    size_t m_year{0};
    std::string m_description{""};
    
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    
    template<typename T>
    void fixSpelling(T spellChecker){
        spellChecker(m_title);
        spellChecker(m_description);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    
    void trim(std::string& str) const;
};

}

#endif /* SDDS_MOVIE_H */
