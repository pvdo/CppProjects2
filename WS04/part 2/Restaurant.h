//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.cpp
//  ws04-part2

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <stdio.h>
#include <iostream>
#include  "Reservation.h"

namespace sdds{
class Restaurant{
    Reservation* reserv = nullptr;
    size_t counter = 0;
    
public:
    Restaurant();
    Restaurant(Reservation* reservations[], size_t cnt);
    Restaurant(const Restaurant& res);
    Restaurant& operator=(const Restaurant& res);
    Restaurant(Restaurant&& res);
    Restaurant& operator=(Restaurant&& res);
    ~Restaurant();
    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, Restaurant& res);
    
};
}
#endif /* SDDS_RESTAURANT_H */
