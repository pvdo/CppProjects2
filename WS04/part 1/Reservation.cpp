//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.cpp
//  ws04


#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Reservation.h"

namespace sdds{

Reservation::Reservation(){}

Reservation::Reservation(const std::string& res){
    std::string temp = res;
    
    temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace),temp.end());
    
    reservationId = temp.substr(0, temp.find(":"));
    temp.erase(0, temp.find(":") + 1);
    
    name = temp.substr(0, temp.find(","));
    temp.erase(0, temp.find(",") + 1);

    email = temp.substr(0, temp.find(","));
    temp.erase(0, temp.find(",")+ 1);
    
    numOfPeople = std::stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",") + 1 );
                            
    day = std::stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",") + 1);
    
    hour = std::stoi(temp.substr(0, temp.find('\n')));
}

std::ostream& operator<<(std::ostream& os, Reservation& res){
    
    std::string email = "  <" + res.email + ">";
    if(res.hour >= 6 && res.hour <= 9){
        os << "Reservation " << res.reservationId << ":" << std::setw(11) << std::right << res.name
        << std::setw(26) << std::left << email
        << "Breakfast on day " << res.day << " @ " << res.hour << ":00 "
        << "for " << res.numOfPeople << " people." << std::endl;
    }
    
    else if(res.hour >= 11 && res.hour <= 15){
        os << "Reservation " << res.reservationId << ":" << std::setw(11) << std::right << res.name
        << std::setw(26) << std::left << email
        << "Lunch on day " << res.day << " @ " << res.hour << ":00 "
        << "for " << res.numOfPeople << " people." << std::endl;
    }
    
    else if(res.hour >= 17 && res.hour <= 21){
        os << "Reservation " << res.reservationId << ":" << std::setw(11) << std::right << res.name
        << std::setw(26) << std::left << email
        << "Dinner on day " << res.day << " @ " << res.hour << ":00 "
        << "for " << res.numOfPeople << " people." << std::endl;
    }
    else{
        os << "Reservation " << res.reservationId << ":" << std::setw(11) << std::right << res.name
        << std::setw(26) << std::left << email
        << "Drinks on day " << res.day << " @ " << res.hour << ":00 "
        << "for " << res.numOfPeople << " people." << std::endl;
    }
    
    return os;
}



}
                            
                            
