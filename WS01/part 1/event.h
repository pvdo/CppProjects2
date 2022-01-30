//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/05/27

//  event.hpp
//  ws1-Part1

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <stdio.h>

extern unsigned int g_sysClock;

namespace sdds{

class Event{
    char description[128];
    size_t time;
public:
    Event();
    void display();
    void setDescription(const char *desc);
};
}

#endif /* SDDS_EVENT_H */
