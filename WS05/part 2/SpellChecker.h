//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  SpellChecker.h
//  ws05-part2

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <stdio.h>
#include <iostream>
namespace sdds {
class SpellChecker{
    std::string m_badWords[5]{""};
    std::string m_goodWords[5]{""};
    size_t counter{0};
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text) const;
};
}
#endif /* SDDS_SPELLCHECKER_H */
