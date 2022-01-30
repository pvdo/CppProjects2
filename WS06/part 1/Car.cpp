//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  Car.cpp
//  ws06-part1

#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds {
Car::Car(std::istream& stream){
    std::string temp;
    //do{
        getline(stream, temp);
        if(stream){
            temp.erase(0, temp.find_first_not_of(" "));
            if(temp[0] == 'c' || temp[0] == 'C'){
                //----- MAKER
                //erase tag
                temp.erase(0, temp.find(",") + 1);
                //erase first whitespaces
                temp.erase(0, temp.find_first_not_of(" "));
                //assign tempMaker with whitespaces
                std::string tempMaker = temp.substr(0, temp.find(","));
                //trim whitespaces
                trim(tempMaker);
                //assign to m_maker
                m_maker = tempMaker;
                //erase maker
                temp.erase(0, temp.find(",") + 1);
                
                //----- CONDITION
                //erase first whitespaces
                temp.erase(0, temp.find_first_not_of(" "));
                //assign tempCondition with whitespaces
                std::string tempCondition = temp.substr(0, temp.find(","));
                //trim whitespaces
                trim(tempCondition);
                //assign to m_condition
                if(tempCondition == "n"){
                    m_condition = Condition::brandNew;
                }else if(tempCondition == "u"){
                    m_condition = Condition::used;
                }else if (tempCondition == "b"){
                    m_condition = Condition::broken;
                }
                //erase condition
                temp.erase(0, temp.find(",") + 1);
                
                //------TOP SPEED
                //erase first whitespaces
                temp.erase(0, temp.find_first_not_of(" "));
                //assign tempSpeed with whitespaces
                std::string tempSpeed = temp.substr(0, temp.find(","));
                //trim whitespaces
                trim(tempSpeed);
                //assign to m_topSpeed
                m_topSpeed = std::stod(tempSpeed);
            }
            
        }
   // }while(!stream.eof());
}
std::string Car::condition() const{
    std::string conditionReturn;
    switch(m_condition){
        case Condition::brandNew:
            conditionReturn = "new";
            break;
        case Condition::used:
            conditionReturn = "used";
            break;
        case Condition::broken:
            conditionReturn = "broken";
            break;
    }
    return conditionReturn;
}
double Car::topSpeed() const{
    return m_topSpeed;
}
void Car::display(std::ostream& out) const{
    out << "| " << std::setw(10) << std::right << m_maker
    << " | " << std::setw(6) << std::left << condition()
    << " | " << std::setw(6) << std::fixed << std::setprecision(2) << m_topSpeed
    << " |" << std::endl;
}


void Car::trim(std::string& str) const {
    size_t i = 0u;
    
    for (i = 0u; i < str.length() && str[i] == ' '; ++i);
    str = str.substr(i);
    for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
    str = str.substr(0, i);
}

}

