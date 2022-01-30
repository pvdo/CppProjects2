
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
//
// Last Version: 2020/05/1

//I have done all the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.

//  RecordSet.h
//  ws2-part1

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <string>
#include <chrono>
namespace sdds{
class RecordSet{
    std::string* record;
    size_t countRecords;
public:
    RecordSet();
    RecordSet(char *);
    RecordSet(const RecordSet&);
    RecordSet& operator=(const RecordSet& src);
    ~RecordSet();
    size_t size();
    std::string getRecord(size_t);
};
}
#endif /* RecordSet_hpp */
