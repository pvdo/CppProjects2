//
//  TimedEvents.cpp
//  ws2-part1
//
//  Created by Pedro Do Carmo on 2020-06-01.
//  Copyright © 2020 Pedro Do Carmo. All rights reserved.
//

#include "TimedEvents.h"

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>


namespace sdds {
TimedEvents::TimedEvents(){
    numberRecords = 0;
    for(int i = 0; i < MAX_RECORDS; i++){
        records[i].eventName = "";
        records[i].unitTime = "";
    }
}

void TimedEvents::startClock(){
    start = std::chrono::steady_clock::now();
}
void TimedEvents::stopClock(){
    end = std::chrono::steady_clock::now();
}
void TimedEvents::recordEvent(const char* eName){
    for(int i = 0; i < MAX_RECORDS; i++){
        if(records[i].eventName == ""){
            records[i].eventName = eName;
            records[i].unitTime = "nanoseconds";
            records[i].durationOfRec = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            numberRecords++;
        }
    }
}
    std::ostream &operator <<(std::ostream& os, const TimedEvents& timedE){
        for(unsigned i = 0u; i < timedE.numberRecords; i++){
            os << std::setw(20) << timedE.records[i].eventName
               << std::setw(12) << timedE.records[i].durationOfRec.count()
               << timedE.records[i].unitTime << std::endl;
    }
    return os;
}
}
