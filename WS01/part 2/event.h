//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/05/27

//  event.h
//  ws1-Part2

//I have done all the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <stdio.h>

extern unsigned int g_sysClock;

namespace sdds{

class Event{
    char *description;
    unsigned int time;
public:
    Event();
    Event(const Event &e);
    Event& operator=(const Event &e);
    ~Event();
    void display();
    void setDescription(const char *desc);
    void setEmpty();
};
}

#endif /* SDDS_EVENT_H */


