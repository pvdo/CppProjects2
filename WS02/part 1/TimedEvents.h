
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
//
// Last Version: 2020/05/1

//I have done all the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.

//  TimedEvents.h
//  ws2-part1


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <stdio.h>
#include <iostream>
#include <chrono>

const int MAX_RECORDS = 7;
namespace sdds {

class TimedEvents{
    unsigned int numberRecords = 0;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    struct{
        std::string eventName{};
        std::string unitTime{};
        std::chrono::steady_clock::duration durationOfRec{};
    } records[MAX_RECORDS];
public:
    TimedEvents();
    void startClock();
    void stopClock();
    void recordEvent(const char* eName);
    friend std::ostream &operator <<(std::ostream&, const TimedEvents&);
};
}

#endif /* TimedEvents_hpp */
