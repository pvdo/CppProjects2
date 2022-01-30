//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.h
//  ws04

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds{
class Reservation{
    std::string reservationId{};
    std::string name{};
    std::string email{};
    int numOfPeople{0};
    int day{0};
    int hour{0};
public:
    Reservation();
    Reservation(const std::string& res);
    friend std::ostream& operator<<(std::ostream& os, Reservation& res);
    
};
}
#include <stdio.h>

#endif /* Reservation_hpp */
