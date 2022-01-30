//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
//
// Last Version: 2020/05/31

//  event.cpp
//  ws1-Part2
//I have done all the coding by myself and only copied the code that my professor provided to
//complete my workshops and assignments.


#include "event.h"

#include <cstring>
#include <iostream>

unsigned int g_sysClock = 0;
using namespace std;

namespace sdds{
Event::Event(){
    description = nullptr;
    time = 0;
}

Event::Event(const Event &e){
    setEmpty();

    if(e.description != nullptr){
        description = new char[strlen(e.description) + 1];
        strcpy(description, e.description);
        time  = e.time;
    }
}

Event& Event::operator=(const Event& e) {

    if (this != &e) {
        setEmpty();

        if (e.description != nullptr) {
            description = new char[strlen(e.description) + 1];
            strcpy(description, e.description);
            time = e.time;
        }
    }
        return *this;
}

void Event::setEmpty() {
    this->time = 0;
    if (description != nullptr && description[0] != '\0'){
        delete [] description;
        description = nullptr;
    }
}

void Event::display(){
    static int counter = 0;
    counter++;
    static unsigned int hour = 0;
    static unsigned int min = 0;
    static unsigned int sec = 0;
    
    std::cout.fill (' ');
    std::cout.width(3);
    cout << counter << ". ";

    if(description != nullptr && description[0] != '\0'){
        hour = time/3600;
        min = (time%3600)/60;
        sec = (time%3600)%60;

        std::cout.width(2);
        std::cout.fill ('0');
        cout << hour << ":";
        std::cout.width(2);
        cout << min << ":";
        std::cout.width(2);
        cout << sec << " -> " << description << endl;
    }
    else
        cout << "[ No Event ]" << endl;

}

void Event::setDescription(const char *desc){
    time = g_sysClock;
    delete [] description;
    description = nullptr;
    if(desc != nullptr && desc[0] != '\0'){
        int length = strlen(desc);
        description = new char [length + 1];
        strcpy(description, desc);
        description[length] = '\0';
    }else{
        time = 0;
    }
}

Event::~Event(){
    if (description != nullptr) {
        delete[] description;
        description = nullptr;
    }
}
}
