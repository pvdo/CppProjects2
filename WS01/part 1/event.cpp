//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/05/27

//  event.cpp
//  ws1-Part1


#include "event.h"

#include <cstring>
#include <iostream>


using namespace std;

namespace sdds{
Event::Event(){
    description[0] = '\0';
    time = 0;
}

int counter = 0;
unsigned int hour = 0;
unsigned int min = 0;
unsigned int sec = 0;

void Event::display(){

    hour = time/3600;
    min = (time%3600)/60;
    sec = (time%3600)%60;
    
    counter++;
    std::cout.fill (' ');
    std::cout.width(3);
    cout << counter << ". ";
    
    if(description[0] != '\0'){
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
    if(desc != nullptr && desc[0] != '\0'){
        strcpy(description, desc);
    }else{
        description[0] = '\0';
        time = 0;
    }
}
}
