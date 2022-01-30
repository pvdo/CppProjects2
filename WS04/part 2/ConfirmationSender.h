//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/15

//  Reservation.cpp
//  ws04-part2

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <stdio.h>
#include "Reservation.h"
#include "Restaurant.h"
namespace sdds{
class ConfirmationSender{
    const Reservation** confirmRes;
    size_t counter = 0;

public:
    ConfirmationSender();
    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);
    ConfirmationSender(ConfirmationSender& cs);
    ConfirmationSender(ConfirmationSender&& cs);
    ConfirmationSender& operator=(const ConfirmationSender& cs);
    ConfirmationSender& operator=(ConfirmationSender&& cs);
    ~ConfirmationSender();
    friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& cs);
};

}
#endif /* SDDS_CONFIRMATIONSENDER_H */
