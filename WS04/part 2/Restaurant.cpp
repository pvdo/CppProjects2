//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.cpp
//  ws04-part2

#include <iostream>
#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {
Restaurant::Restaurant(){
    reserv = nullptr;
}

Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
    delete [] reserv;
    reserv = new Reservation [cnt];
    Reservation temp;
    
    for(size_t i = 0; i < cnt; i++){
        reserv[i] = *reservations[i];
        counter++;
    }
   
}
size_t Restaurant::size() const{
    return counter;
}

Restaurant::Restaurant(const Restaurant& res){
    *this = res;
}
Restaurant& Restaurant::operator=(const Restaurant& res){
    if (this != &res) {
        delete [] reserv;
        reserv = new Reservation[res.counter];
        for(size_t i = 0; i < res.counter; i++){
            reserv[i] = res.reserv[i];
        }
            counter = res.counter;
        }
    return *this;
}
Restaurant::Restaurant(Restaurant&& res){
    delete [] reserv;
    reserv = res.reserv;
    counter = res.counter;
    res.reserv = nullptr;
    res.counter = 0;
}
Restaurant& Restaurant::operator=(Restaurant&& res){
    if (this != &res) {
        delete [] reserv;
        reserv = res.reserv;
        counter = res.counter;
        res.reserv = nullptr;
        res.counter = 0;
    }
    return *this;
}
Restaurant::~Restaurant(){
    delete [] reserv;
}



std::ostream& operator<<(std::ostream& os, Restaurant& res){
    os << "--------------------------" << std::endl;
    os << "Fancy Restaurant" << std::endl;
    os << "--------------------------" << std::endl;
    if(res.counter == 0){
        os << "The object is empty!" << std::endl;
    }else{
        for(size_t i = 0; i < res.counter; i++)
            os << res.reserv[i];
    }
    os << "--------------------------" << std::endl;
    return os;
}
}

