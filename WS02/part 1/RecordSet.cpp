
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
//
// Last Version: 2020/05/1

//I have done all the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.

//  RecordSet.cpp
//  ws2-part1

#include "RecordSet.h"
#include <iostream>
#include <cstring>
#include <chrono>
#include <fstream>

namespace sdds {


RecordSet::RecordSet(){
    record = nullptr;
    countRecords = 0;
}
RecordSet::RecordSet(char* fileName){
    std::ifstream in(fileName);
    std::string line;
    while (getline(in, line)){
        
        if(test == " ")
            countRecords++;
    }
    record = new std::string[countRecords];
    
    for(size_t i = 0; i < countRecords; ++i){
            getline (in, record[i], ' ');
        }
    in.close();
}
RecordSet::RecordSet(const RecordSet& src){
 //   *this = src;
    if(src.record !=nullptr){
       // delete [] record;
        record = new std::string[src.countRecords];
        for(size_t i = 0; i < src.countRecords; ++i){
            record[i] = src.record[i];
        }
        countRecords = src.countRecords;
    }
}

RecordSet& RecordSet::operator=(const RecordSet& src){
    if(this != &src){
        if(record != nullptr)
            delete [] record;
        record = new std::string[src.countRecords];
        for(size_t i = 0; i < src.countRecords; ++i){
            record[i] = src.record[i];
        }
        countRecords = src.countRecords;
    }
    return *this;
}
RecordSet::~RecordSet(){
    delete [] record;
}
size_t RecordSet::size(){
    return countRecords;
}
std::string RecordSet::getRecord(size_t index){
    std::string rec;
    if(index <= countRecords && index >= 0 && record != nullptr){
        rec = record[index];
    }else{
        rec = "";
    }
    return rec;
}
}
