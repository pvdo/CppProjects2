//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/08

//  pair.h
//  ws3-Part2

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <stdio.h>
#include "Set.h"

namespace sdds {
template <class T, int N, class K, class V>
class SetSummable : public Set<T,N>{
    K m_key{};
    V m_value{};
public:
    SetSummable(){}
    V accumulate(const K& key) const{
        V accumulator = T::getInicialValue();
        for(int i = 0; i < Set<T,N>::size(); i++){
            if(key == m_key ){
                accumulator = key[i] + accumulator;
            }
        }
        
        return accumulator;
    }
};
}
#endif /* SDDS_SETSUMMABLE_H */
