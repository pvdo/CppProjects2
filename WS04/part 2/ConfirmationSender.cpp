//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.cpp
//  ws04-part2

#include "ConfirmationSender.h"

namespace sdds{

ConfirmationSender::ConfirmationSender(){
    confirmRes = nullptr;
}

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
    if(confirmRes == nullptr && counter == 0){

        confirmRes = new const Reservation* [counter + 1];

        confirmRes[counter] = &res;
        counter++;
    }else{
        bool same = false;
        for(size_t i = 0; i < counter; i++){
            if(confirmRes[i] == &res){
                same = true;
            }
        }

        if(!same){
            const Reservation** temp = nullptr;
            temp = new const Reservation* [counter];
            for(size_t i = 0; i < counter; i++){
                temp[i] = confirmRes[i];
            }

            delete [] confirmRes;

            confirmRes = new const Reservation* [counter + 1];

            for(size_t i = 0; i < counter; i++){
                confirmRes[i] = temp[i];
            }

            confirmRes[counter] = &res;
            counter++;
            
            delete [] temp;
        }
    }
    return *this;
}
ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
    for(size_t i = 0; i < counter; i++){
        if(confirmRes[i] == &res){
            confirmRes[i] = nullptr;
            counter--;
        }
        
    }
    return *this;
}

ConfirmationSender::ConfirmationSender(ConfirmationSender& cs){
    *this = cs;
}

ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs){
    confirmRes = cs.confirmRes;
    counter = cs.counter;
    cs.confirmRes = nullptr;
    cs.counter = 0;
}

ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs){
    if (this != &cs) {
        confirmRes = new const Reservation* [cs.counter];
        for(size_t i = 0; i < cs.counter; i++){
            confirmRes[i] = cs.confirmRes[i];
        }
            counter = cs.counter;
        }
    return *this;
}

ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs){
    if (this != &cs) {
        delete [] confirmRes;
        confirmRes = cs.confirmRes;
        counter = cs.counter;
        cs.confirmRes = nullptr;
        cs.counter = 0;

    }
    return *this;
}

ConfirmationSender::~ConfirmationSender(){
    delete [] confirmRes;
}

std::ostream& operator<<(std::ostream& os, ConfirmationSender& cs){
    os << "--------------------------" << std::endl;
    os << "Confirmations to Send" << std::endl;
    os << "--------------------------" << std::endl;
    if(cs.counter == 0){
        os << "The object is empty!" << std::endl;
    }else{
        Reservation temp;
        for(size_t i = 0; i < cs.counter; i++){
            temp = *cs.confirmRes[i];
            os << temp;
        }
    }
    os << "--------------------------" << std::endl;
    return os;
}
}
