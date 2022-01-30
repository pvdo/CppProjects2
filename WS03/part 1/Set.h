//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/08

//  set.h
//  ws3-Part1

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <stdio.h>

namespace sdds{
template<typename T, int N>
class Set{
    T array[N]{};
    size_t count{0};

public:
    size_t size() const{
        return N;
        
    }
    const T& operator[](size_t idx)const{
//        if(idx >= 0){
//            T returnValue = array[idx];
//        }
        return array[idx];
    }
    void operator+=(const T& item){
        if(count < N){
            array[count] = item;
            count++;
        }
    }
};

}
#endif /* set_h */
